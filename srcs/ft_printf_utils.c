/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:09:45 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/25 21:46:47 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_tab_index(t_flags *stru)
{
	stru->tab_index[0] = 'c';
	stru->tab_index[1] = 's';
	stru->tab_index[2] = 'p';
	stru->tab_index[3] = 'd';
	stru->tab_index[4] = 'i';
	stru->tab_index[5] = 'u';
	stru->tab_index[6] = 'x';
	stru->tab_index[7] = 'X';
	stru->tab_index[8] = '%';
	stru->tab_index[9] = '\0';
}

void	ft_init_tab_fct(t_flags *stru)
{
	stru->tab_fct[0] = &ft_print_c;
	stru->tab_fct[1] = &ft_print_s;
	stru->tab_fct[2] = &ft_print_p;
	stru->tab_fct[3] = &ft_print_d;
	stru->tab_fct[4] = &ft_print_d;
	stru->tab_fct[5] = &ft_print_d;
	stru->tab_fct[6] = &ft_print_d;
	stru->tab_fct[7] = &ft_print_d;
	stru->tab_fct[8] = &ft_print_per;
}

void	ft_print_sp_ze(t_flags *stru, char c)
{
	while (stru->spaces > 0)
	{
		if (c == ' ')
			write(1, " ", 1);
		else if (c == '0')
			write(1, "0", 1);
		stru->spaces--;
		stru->count_print++;
	}
}

void	ft_init_str_null(t_flags *stru)
{
	stru->str_null[0] = '(';
	stru->str_null[1] = 'n';
	stru->str_null[2] = 'u';
	stru->str_null[3] = 'l';
	stru->str_null[4] = 'l';
	stru->str_null[5] = ')';
	stru->str_null[6] = '\0';
}

void	ft_re_init_stru(t_flags *stru)
{
	stru->width = 0;
	stru->sign = 0;
	stru->point = 0;
	stru->zero = 0;
	stru->star = 0;
	stru->precision = 0;
	stru->star2 = 0;
	stru->len_arg = 0;
	stru->spaces = 0;
	stru->nb_zeros = 0;
	stru->success = 0;
	free(stru->tmpflags);
	stru->tmpflags = NULL;
	stru->tmpindex = 0;
	stru->k = 0;
	stru->i = 0;
	stru->j = 0;
	stru->arg = NULL;
	stru->num = 0;
	stru->num_u = 0;
	stru->num_ull = 0;
}
