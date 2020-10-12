/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 01:57:34 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/08/28 01:46:48 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				setflag(long *n, int *len, t_flags *flag, int judge)
{
	if (*n < 0 && judge)
	{
		flag->minus = 1;
		*n *= -1;
	}
	if ((*n == 0) && (flag->dot == 1))
		*len = 0;
	flag->acc = (flag->acc < *len) ? *len : flag->acc;
	if (flag->flag[0] == 1 && flag->dot == 1)
		flag->flag[0] = -1;
}

void				ft_treat_int(t_flags *flag)
{
	long			n;
	int				len;

	n = (long)va_arg(flag->args, int);
	len = calc_digit(n, 10);
	setflag(&n, &len, flag, 1);
	if (flag->flag[1] == -1)
	{
		if (flag->flag[0] == -1)
			ft_putchar_n(' ', flag->width - flag->minus - flag->acc, flag);
		ft_putchar_n('-', flag->minus, flag);
		if (flag->flag[0] == 1)
			ft_putchar_n('0', flag->width - flag->minus - flag->acc, flag);
		ft_putchar_n('0', flag->acc - len, flag);
		if (len != 0)
			print_xx_dic("0123456789", n, 10, flag);
	}
	else
	{
		ft_putchar_n('-', flag->minus, flag);
		ft_putchar_n('0', flag->acc - len, flag);
		if (len != 0)
			print_xx_dic("0123456789", n, 10, flag);
		ft_putchar_n(' ', flag->width - flag->minus - flag->acc, flag);
	}
}

void				ft_treat_unint(t_flags *flag)
{
	long			n;
	int				len;

	n = (long)va_arg(flag->args, unsigned int);
	len = calc_digit(n, 10);
	setflag(&n, &len, flag, 0);
	if (flag->flag[1] == -1)
	{
		if (flag->flag[0] == -1)
			ft_putchar_n(' ', flag->width - flag->minus - flag->acc, flag);
		if (flag->flag[0] == 1)
			ft_putchar_n('0', flag->width - flag->minus - flag->acc, flag);
		ft_putchar_n('0', flag->acc - len, flag);
		if (len != 0)
			print_xx_dic("0123456789", n, 10, flag);
	}
	else
	{
		ft_putchar_n('0', flag->acc - len, flag);
		if (len != 0)
			print_xx_dic("0123456789", n, 10, flag);
		ft_putchar_n(' ', flag->width - flag->minus - flag->acc, flag);
	}
}

void				ft_treat_p(t_flags *flag)
{
	long			n;
	int				len;

	n = (long)va_arg(flag->args, void*);
	len = calc_digit(n, 16);
	setflag(&n, &len, flag, 0);
	if (flag->flag[1] == -1)
	{
		if (flag->flag[0] == -1)
			ft_putchar_n(' ', flag->width - 2 - flag->acc, flag);
		ft_putstr_n("0x", flag, 2);
		if (flag->flag[0] == 1)
			ft_putchar_n('0', flag->width - 2 - flag->acc, flag);
		ft_putchar_n('0', flag->acc - len, flag);
		if (len != 0)
			print_xx_dic("0123456789abcdef", n, 16, flag);
	}
	else
	{
		ft_putstr_n("0x", flag, 2);
		ft_putchar_n('0', flag->acc - len, flag);
		if (len != 0)
			print_xx_dic("0123456789abcdef", n, 16, flag);
		ft_putchar_n(' ', flag->width - 2 - flag->acc, flag);
	}
}

void				ft_treat_x(t_flags *flag, char *s)
{
	long			n;
	int				len;

	n = (long)va_arg(flag->args, unsigned int);
	len = calc_digit(n, 16);
	setflag(&n, &len, flag, 0);
	if (flag->flag[1] == -1)
	{
		if (flag->flag[0] == -1)
			ft_putchar_n(' ', flag->width - flag->acc, flag);
		if (flag->flag[0] == 1)
			ft_putchar_n('0', flag->width - flag->acc, flag);
		ft_putchar_n('0', flag->acc - len, flag);
		if (len != 0)
			print_xx_dic(s, n, 16, flag);
	}
	else
	{
		ft_putchar_n('0', flag->acc - len, flag);
		if (len != 0)
			print_xx_dic(s, n, 16, flag);
		ft_putchar_n(' ', flag->width - flag->acc, flag);
	}
}
