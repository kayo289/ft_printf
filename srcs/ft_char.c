/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:02:31 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/08/26 01:47:09 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_strchr_n(char *s, char *c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != *c)
		i++;
	if (s[i] == *c)
		return (i);
	return (-1);
}

int			calc_digit(long long n, int base)
{
	int		cnt;

	cnt = 1;
	while (n / base != 0)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}
