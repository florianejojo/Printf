/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:09:47 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/25 19:22:05 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_zero_p(t_flags *stru)
{
	while (stru->nb_zeros > 0)
	{
		write(1, "0", 1);
		stru->nb_zeros--;
		stru->count_print++;
	}
}

void	ft_print_arg_p(t_flags *stru)
{
	if (stru->sign == 0 && stru->zero == 0)
		ft_print_sp_ze(stru, ' ');
	if (stru->arg[0] == '-')
	{
		write(1, "-", 1);
		stru->count_print++;
		stru->i++;
	}
	write(1, "0x", 2);
	stru->count_print = stru->count_print + 2;
	if (stru->sign == 0)
		ft_print_sp_ze(stru, '0');
	ft_print_zero_p(stru);
	if (stru->point == 1 && stru->precision == 0 && stru->arg[0] == '0')
		write(1, "", 0);
	else
		while (stru->arg[stru->i])
		{
			write(1, &stru->arg[stru->i++], 1);
			stru->count_print++;
		}
	if (stru->sign == 1)
		ft_print_sp_ze(stru, ' ');
}

void	ft_nb_spaces_p(t_flags *stru)
{
	if (stru->precision == 0 && stru->point == 1 && stru->arg[0] == '0')
		stru->spaces = 1;
	if (stru->precision <= stru->len_arg)
		stru->spaces = stru->width - stru->len_arg + stru->spaces - 2;
	else if (stru->arg[0] == '-')
		stru->spaces = stru->width - stru->precision - 1 + stru->spaces;
	else
		stru->spaces = stru->width - stru->precision + stru->spaces - 2;
}

void	ft_print_p(t_flags *stru)
{
	ft_init_stru(stru);
	stru->num_ull = va_arg(stru->arg_list, unsigned long long);
	stru->arg = ft_itoa_base(stru->num_ull, "0123456789abcdef");
	stru->len_arg = ft_strlen(stru->arg);
	ft_nb_spaces_p(stru);
	if (stru->precision > stru->len_arg && stru->arg[0] == '-')
		stru->nb_zeros = stru->precision - stru->len_arg + 1;
	else
		stru->nb_zeros = stru->precision - stru->len_arg;
	ft_print_arg_p(stru);
	free(stru->arg);
}
