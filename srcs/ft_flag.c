/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 04:13:27 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/08/26 02:06:17 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		set_flag(t_flags *flag)
{
	int		n;

	while ((n = ft_strchr_n("0-", flag->format)) >= 0)
	{
		flag->flag[n] = 1;
		flag->format++;
	}
}

int			ft_substr2num(t_flags *flag, int is_w)
{
	int		ans;

	if (*(flag->format) != '*')
	{
		ans = 0;
		while (ft_isdigit(*(flag->format)) && flag->format)
			ans = ans * 10 + *(flag->format++) - '0';
	}
	else
	{
		ans = va_arg(flag->args, int);
		if (is_w && ans < 0)
		{
			flag->flag[1] = 1;
			ans *= -1;
		}
		else if (!is_w && ans < 0)
		{
			flag->dot = 0;
			flag->acc = -1;
		}
		flag->format++;
	}
	return (ans);
}
