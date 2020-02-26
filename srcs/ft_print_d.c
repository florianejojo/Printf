/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:52:30 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/25 22:11:33 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_zero(t_flags *stru)
{
	while (stru->nb_zeros > 0)
	{
		write(1, "0", 1);
		stru->nb_zeros--;
		stru->count_print++;
	}
}

void	ft_print_arg_d(t_flags *stru)
{
	if (stru->sign == 0 && stru->zero == 0)
		ft_print_sp_ze(stru, ' ');
	if (stru->arg[0] == '-')
	{
		write(1, "-", 1);
		stru->count_print++;
		stru->i++;
	}
	if (stru->sign == 0)
		ft_print_sp_ze(stru, '0');
	ft_print_zero(stru);
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

void	ft_nb_spaces_d(t_flags *stru)
{
	if (stru->precision == 0 && stru->point == 1 && stru->arg[0] == '0')
		stru->spaces = 1;
	if (stru->precision < stru->len_arg)
		stru->spaces = stru->width - stru->len_arg + stru->spaces;
	else if (stru->arg[0] == '-')
		stru->spaces = stru->width - stru->precision - 1 + stru->spaces;
	else
		stru->spaces = stru->width - stru->precision + stru->spaces;
}

void	ft_print_d(t_flags *stru)
{
	ft_init_stru(stru);
	if (stru->type == 'd' || stru->type == 'i')
	{
		stru->num = va_arg(stru->arg_list, int);
		stru->arg = ft_itoa(stru->num);
	}
	else if (stru->type == 'u' || stru->type == 'x' || stru->type == 'X')
	{
		stru->num_u = va_arg(stru->arg_list, unsigned int);
		if (stru->type == 'u')
			stru->arg = ft_itoa(stru->num_u);
		if (stru->type == 'x')
			stru->arg = ft_itoa_base(stru->num_u, "0123456789abcdef");
		if (stru->type == 'X')
			stru->arg = ft_itoa_base(stru->num_u, "0123456789ABCDEF");
	}
	stru->len_arg = ft_strlen(stru->arg);
	ft_nb_spaces_d(stru);
	if (stru->precision >= stru->len_arg && stru->arg[0] == '-')
		stru->nb_zeros = stru->precision - stru->len_arg + 1;
	else
		stru->nb_zeros = stru->precision - stru->len_arg;
	ft_print_arg_d(stru);
	free(stru->arg);
}
