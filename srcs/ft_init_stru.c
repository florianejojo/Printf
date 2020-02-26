/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:18:49 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/25 21:35:45 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_stru(t_flags *stru)
{
	int i;

	i = 1;
	stru->type = stru->tmpflags[ft_strlen(stru->tmpflags) - 1];
	while (stru->tmpflags[i] && (stru->tmpflags[i] == '-' ||
				stru->tmpflags[i] == '+' || stru->tmpflags[i] == '0'))
	{
		if (stru->tmpflags[i] == '-')
			stru->sign = 1;
		if (stru->tmpflags[i] == '0')
			stru->zero = 1;
		i++;
	}
	ft_init_width(stru, i);
}

void	ft_init_width(t_flags *stru, int i)
{
	if (stru->tmpflags[i] && (stru->tmpflags[i] >= '0' &&
				stru->tmpflags[i] <= '9'))
	{
		while (stru->tmpflags[i] && (stru->tmpflags[i] >= '0' &&
					stru->tmpflags[i] <= '9'))
		{
			stru->width = stru->width * 10 + (stru->tmpflags[i] - '0');
			i++;
		}
	}
	else if (stru->tmpflags[i] && stru->tmpflags[i] == '*')
	{
		stru->width = va_arg(stru->arg_list, int);
		if (stru->width < 0)
		{
			stru->sign = 1;
			stru->width = -stru->width;
		}
		i++;
	}
	ft_init_precision(stru, i);
}

void	ft_init_precision(t_flags *stru, int i)
{
	if (stru->tmpflags[i] && stru->tmpflags[i] == '.')
	{
		stru->point = 1;
		i++;
	}
	if (stru->tmpflags[i] && (stru->tmpflags[i] >= '0' &&
				stru->tmpflags[i] <= '9'))
	{
		while (stru->tmpflags[i] && (stru->tmpflags[i] >= '0' &&
					stru->tmpflags[i] <= '9'))
			stru->precision = stru->precision * 10 +
				(stru->tmpflags[i++] - '0');
	}
	else if (stru->tmpflags[i] && stru->tmpflags[i] == '*')
	{
		stru->precision = va_arg(stru->arg_list, int);
		i++;
	}
	ft_rectif(stru);
}

void	ft_rectif(t_flags *stru)
{
	if (stru->sign == 1 && stru->zero == 1)
		stru->zero = 0;
	if (stru->point == 1 && stru->precision < 0)
	{
		stru->point = 0;
		stru->precision = 0;
	}
	if (stru->point == 1 && stru->zero == 1)
	{
		if (stru->type == 'd' || stru->type == 'i' || stru->type == 'u')
			stru->zero = 0;
		if (stru->type == 'x' || stru->type == 'X' || stru->type == 'p')
			stru->zero = 0;
	}
}
