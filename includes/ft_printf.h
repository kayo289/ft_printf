/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 22:42:29 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/08/26 16:07:10 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int			flag[2];
	int			width;
	int			acc;
	int			dot;
	int			minus;
	char		*format;
	va_list		args;
	int			len;
	char		type;
}				t_flags;
void			ft_main_print(t_flags *flag);
int				ft_vprintf(t_flags *flag);
int				ft_printf(const char *format, ...);
void			setflag(long *n, int *len, t_flags *flag, int judge);
void			ft_treat_char(t_flags *flag);
void			ft_treat_str(t_flags *flag);
void			ft_treat_int(t_flags *flag);
void			ft_treat_unint(t_flags *flag);
void			ft_treat_p(t_flags *flag);
void			ft_treat_x(t_flags *flag, char *s);
void			ft_treat_per(t_flags *flag);
int				ft_strchr_n(char *s, char *c);
void			ft_putchar(char c, t_flags *flag);
void			ft_putstr_n(char *s, t_flags *flag, int n);
void			ft_putchar_n(char s, int n, t_flags *flag);
void			print_xx_dic(char *s, unsigned long num, \
int base, t_flags *flag);
int				calc_digit(long long n, int base);
void			set_flag(t_flags *flag);
int				ft_substr2num(t_flags *flag, int is_w);

#endif
