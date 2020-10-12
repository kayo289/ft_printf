/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 01:45:00 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/08/26 01:47:16 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putchar(char c, t_flags *flag)
{
	write(1, &c, 1);
	flag->len++;
}

void		ft_putstr_n(char *s, t_flags *flag, int n)
{
	int i;

	i = 0;
	while (s[i] != '\0' && i < n)
		ft_putchar(s[i++], flag);
}

void		ft_putchar_n(char s, int n, t_flags *flag)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(s, flag);
		i++;
	}
}

void		print_xx_dic(char *s, unsigned long num, int base, t_flags *flag)
{
	if (num < (unsigned long)base)
	{
		ft_putchar(s[num % base], flag);
		return ;
	}
	print_xx_dic(s, num / base, base, flag);
	ft_putchar(s[num % base], flag);
}
