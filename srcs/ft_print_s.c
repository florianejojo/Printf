/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:01:20 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/20 15:49:35 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_arg_s(t_flags *stru, char *arg, int i)
{
	if (stru->sign == 0)
	{
		ft_print_sp_ze(stru, ' ');
		ft_print_zero(stru);
	}
	while (stru->point == 1 && stru->len_arg > 0 && stru->precision > 0)
	{
		write(1, &arg[i++], 1);
		stru->len_arg--;
		stru->precision--;
		stru->count_print++;
	}
	while (stru->point == 0 && stru->len_arg > 0)
	{
		write(1, &arg[i++], 1);
		stru->len_arg--;
		stru->count_print++;
	}
	if (stru->sign == 1)
	{
		ft_print_sp_ze(stru, ' ');
	}
}

void	ft_nb_spaces(t_flags *stru, char *arg)
{
	if (arg == NULL)
		stru->spaces = stru->width - 6;
	if (stru->width > stru->len_arg)
	{
		if (stru->point == 0 || stru->precision > stru->len_arg)
			stru->spaces = stru->width - stru->len_arg;
		else
			stru->spaces = stru->width - stru->precision;
	}
	else
	{
		if (stru->point == 1 && stru->precision < stru->width)
			stru->spaces = stru->width - stru->precision;
	}
}

void	ft_print_s(t_flags *stru)
{
	char	*arg;
	int		i;

	i = 0;
	ft_init_stru(stru);
	arg = va_arg(stru->arg_list, char*);
	if (arg == NULL)
	{
		arg = ft_strdup(stru->str_null);
		stru->k = 1;
	}
	stru->len_arg = ft_strlen(arg);
	ft_nb_spaces(stru, arg);
	if (stru->zero == 1)
	{
		stru->nb_zeros = stru->spaces;
		stru->spaces = 0;
	}
	ft_print_arg_s(stru, arg, i);
	if (stru->k == 1)
		free(arg);
}
