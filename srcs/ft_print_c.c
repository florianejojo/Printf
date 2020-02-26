/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:41:47 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/18 22:17:42 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_left(t_flags *stru, char arg)
{
	write(1, &arg, 1);
	stru->count_print++;
	stru->width--;
	while (stru->width > 0)
	{
		write(1, " ", 1);
		stru->width--;
		stru->count_print++;
	}
}

void	ft_right(t_flags *stru, char arg)
{
	stru->spaces = stru->width - 1;
	while (stru->spaces > 0)
	{
		write(1, " ", 1);
		stru->spaces--;
		stru->count_print++;
	}
	write(1, &arg, 1);
	stru->count_print++;
}

void	ft_print_c(t_flags *stru)
{
	char arg;

	ft_init_stru(stru);
	arg = va_arg(stru->arg_list, int);
	if (stru->width <= 1)
	{
		write(1, &arg, 1);
		stru->count_print++;
	}
	else if (stru->sign == 1)
		ft_left(stru, arg);
	else
		ft_right(stru, arg);
}
