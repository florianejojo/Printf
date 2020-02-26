/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:39:44 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/18 22:57:23 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_zero_per(t_flags *stru)
{
	while (stru->nb_zeros > 0)
	{
		write(1, "0", 1);
		stru->nb_zeros--;
		stru->count_print++;
	}
}

void	ft_print_num_per(t_flags *stru)
{
	int	i;

	i = 0;
	if (stru->sign == 0)
		ft_print_sp_ze(stru, ' ');
	ft_print_zero_per(stru);
	if (stru->point == 1 && stru->precision == 0)
		write(1, "", 0);
	else
	{
		write(1, "%", 1);
		stru->count_print++;
	}
	if (stru->sign == 1)
		ft_print_sp_ze(stru, ' ');
}

void	ft_nb_spaces_per(t_flags *stru)
{
	if (stru->point == 1 && stru->precision == 0)
		stru->spaces = stru->width - stru->len_arg - stru->nb_zeros + 1;
	else if (stru->width > stru->len_arg)
		stru->spaces = stru->width - stru->len_arg - stru->nb_zeros;
	else
		stru->spaces = 0;
}

void	ft_print_per(t_flags *stru)
{
	int	i;

	i = 0;
	ft_init_stru(stru);
	stru->len_arg = 1;
	if (stru->precision > stru->len_arg)
		stru->nb_zeros = stru->precision - stru->len_arg + 1;
	else if (stru->precision > stru->len_arg)
		stru->nb_zeros = stru->precision - stru->len_arg;
	else if (stru->zero == 1 && stru->width > stru->len_arg)
		stru->nb_zeros = stru->width - stru->len_arg;
	ft_nb_spaces_per(stru);
	ft_print_num_per(stru);
}
