/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 04:31:55 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/08/26 02:39:16 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_treat_char(t_flags *flag)
{
	char	c;

	c = (char)va_arg(flag->args, int);
	if ((flag->flag[0] == 1) && (flag->flag[1] == -1))
		ft_putchar_n('0', flag->width - 1, flag);
	if (flag->flag[0] == -1 && flag->flag[1] == -1)
		ft_putchar_n(' ', flag->width - 1, flag);
	ft_putchar(c, flag);
	if (flag->flag[1] == 1)
		ft_putchar_n(' ', flag->width - 1, flag);
}

void		ft_treat_str(t_flags *flag)
{
	char	*s;
	int		len;

	s = va_arg(flag->args, char*);
	s = s ? s : "(null)";
	if (((int)ft_strlen(s) > flag->acc) && (flag->dot == 1))
		len = flag->acc;
	else
		len = ft_strlen(s);
	if ((flag->dot == 1) && (flag->acc == 0))
		len = 0;
	if (flag->flag[0] == 1 && flag->flag[1] == -1)
		ft_putchar_n('0', flag->width - len, flag);
	if (flag->flag[0] == -1 && flag->flag[1] == -1)
		ft_putchar_n(' ', flag->width - len, flag);
	ft_putstr_n(s, flag, len);
	if (flag->flag[1] == 1)
		ft_putchar_n(' ', flag->width - len, flag);
}

void		ft_treat_per(t_flags *flag)
{
	char	c;

	c = flag->type;
	if (flag->flag[0] == 1 && flag->flag[1] == -1)
		ft_putchar_n('0', flag->width - 1, flag);
	if (flag->flag[0] == -1 && flag->flag[1] == -1)
		ft_putchar_n(' ', flag->width - 1, flag);
	ft_putchar(c, flag);
	if (flag->flag[1] == 1)
		ft_putchar_n(' ', flag->width - 1, flag);
}
