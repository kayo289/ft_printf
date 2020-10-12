/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 22:41:40 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/08/26 02:06:27 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_main_print(t_flags *flag)
{
	if (flag->type == 'c')
		ft_treat_char(flag);
	else if (flag->type == 's')
		ft_treat_str(flag);
	else if (flag->type == 'd' || flag->type == 'i')
		ft_treat_int(flag);
	else if (flag->type == 'u')
		ft_treat_unint(flag);
	else if (flag->type == 'p')
		ft_treat_p(flag);
	else if (flag->type == 'x')
		ft_treat_x(flag, "0123456789abcdef");
	else if (flag->type == 'X')
		ft_treat_x(flag, "0123456789ABCDEF");
	else if (flag->type == '%')
		ft_treat_per(flag);
}

void		ft_init_flag(t_flags *flag)
{
	flag->flag[0] = -1;
	flag->flag[1] = -1;
	flag->width = 0;
	flag->acc = -1;
	flag->dot = 0;
	flag->minus = 0;
}

int			ft_vprintf(t_flags *flag)
{
	flag->format++;
	ft_init_flag(flag);
	if (*(flag->format) == '\0')
		return (-1);
	set_flag(flag);
	if (*(flag->format) == '\0')
		return (-1);
	flag->width = ft_substr2num(flag, 1);
	if (*(flag->format) == '.')
	{
		flag->dot = 1;
		flag->format++;
		if (*(flag->format) == '\0')
			return (-1);
		flag->acc = ft_substr2num(flag, 0);
	}
	if (*(flag->format) == '\0')
		return (-1);
	flag->type = *(flag->format);
	ft_main_print(flag);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_flags	flag;

	va_start(flag.args, format);
	flag.format = (char*)format;
	flag.len = 0;
	if (format == NULL)
		return (-1);
	while (*(flag.format) != '\0')
	{
		if (*(flag.format) == '%')
		{
			if (ft_vprintf(&flag) == -1)
			{
				flag.len = -1;
				break ;
			}
		}
		else
			ft_putchar(*(flag.format), &flag);
		flag.format++;
	}
	va_end(flag.args);
	return (flag.len);
}
