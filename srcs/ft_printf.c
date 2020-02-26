/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:58:59 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/19 16:53:13 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_find_index(t_flags *stru, char type)
{
	int i;

	i = 0;
	while (stru->tab_index[i])
	{
		if (stru->tab_index[i] == type)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_charset(char c)
{
	char	*charset;
	int		i;

	i = 0;
	charset = "cspdiuxX";
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_do(t_flags *stru, const char *str, int i, int j)
{
	stru->tmpflags = ft_substr(str, j, (i - j + 1));
	if (str[i] == '%')
		stru->tmpindex = 8;
	else
		stru->tmpindex = ft_find_index(stru, str[i]);
	(*stru->tab_fct[stru->tmpindex])(stru);
	ft_re_init_stru(stru);
	stru->success = 1;
}

void	ft_dispatch(t_flags *stru, const char *str, int i, int j)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = i;
			i++;
			while (str[i] && ft_charset(str[i]) == 0 && str[i] != '%')
				i++;
			if (ft_charset(str[i]) == 1 || str[i] == '%')
				ft_do(stru, str, i, j);
			else
			{
				stru->success = 0;
				stru->count_print = 0;
				return ;
			}
		}
		else
		{
			write(1, &str[i], 1);
			stru->count_print++;
		}
		i++;
	}
}

int		ft_printf(const char *str, ...)
{
	t_flags		*stru;
	int			ret;

	stru = (t_flags *)malloc(sizeof(t_flags));
	ft_bzero(stru, sizeof(t_flags));
	va_start(stru->arg_list, str);
	ft_init_tab_index(stru);
	ft_init_tab_fct(stru);
	ft_init_str_null(stru);
	ft_dispatch(stru, str, stru->i, stru->j);
	ret = stru->count_print;
	va_end(stru->arg_list);
	if ((stru->success == 0 && stru->count_print > 0) || stru->success == 1)
	{
		free(stru);
		return (ret);
	}
	else
	{
		free(stru);
		if (str[0] == '\0')
			return (0);
		else
			return (-1);
	}
}
