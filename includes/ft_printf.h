/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:04:19 by flolefeb          #+#    #+#             */
/*   Updated: 2020/02/25 21:52:00 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"

typedef	struct s_flags	t_flags;
struct	s_flags
{
	char				type;
	int					width;
	int					sign;
	int					point;
	int					zero;
	int					nb_zeros;
	int					star;
	int					precision;
	int					star2;
	int					len_arg;
	int					spaces;
	int					count_print;
	int					success;
	char				*tmpflags;
	char				tab_index[10];
	int					tmpindex;
	va_list				arg_list;
	void				(*tab_fct[9])(t_flags*);
	char				str_null[7];
	int					i;
	int					j;
	int					k;
	int					num;
	unsigned int		num_u;
	unsigned long long	num_ull;
	char				*arg;
};

void	ft_print_c(t_flags *stru);
void	ft_print_s(t_flags *stru);
void	ft_print_p(t_flags *stru);
void	ft_print_d(t_flags *stru);
void	ft_print_per(t_flags *stru);

void	ft_print(t_flags *stru, char *arg);

void	ft_init_stru(t_flags *stru);
void	ft_re_init_stru(t_flags *stru);
void	ft_print_sp_ze(t_flags *stru, char c);
void	ft_init_width(t_flags *stru, int i);
void	ft_init_precision(t_flags *stru, int i);
char	*ft_itoa_base(uint64_t value, char *base);
void	ft_right_justif(t_flags *stru, int i, char *arg);
void	ft_left_justif(t_flags *stru, int i, char *arg);
void	ft_init_str_null(t_flags *stru);
void	ft_print_zero(t_flags *stru);
void	ft_rectif(t_flags *stru);

int		ft_printf(const char *str, ...);

void	ft_init_tab_index(t_flags *stru);
void	ft_init_tab_fct(t_flags *stru);

#endif
