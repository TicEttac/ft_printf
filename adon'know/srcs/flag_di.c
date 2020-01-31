/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 02:01:55 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/25 09:32:50 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*zeroeing(char *str, int sign, t_flag *flags)
{
	flags->precision != ERROR ? str = app_precision(str, flags, 'd') : 0;
	if (flags->zero == TRUE && flags->point != TRUE)
	{
		flags->width != ERROR ? str = app_width(str, sign, flags) : 0;
		return (str = app_signe(str, sign, flags));
	}
	str = app_signe(str, sign, flags);
	return (flags->width != FALSE ? str = app_width(str, sign, flags) : str);
}

int		flag_di(va_list arg, t_flag *flags, t_buffer *save)
{
	long d;
	int sign;
	char *str;

	sign = 0;
	d = (long)va_arg(arg, int);
	if (d < 0 ? sign = -1 : 0)
		d *= -1;
	if (d == 0 && flags->point == TRUE)
		str = "";
	else
		str = ft_itoa(d);
	str = zeroeing(str, sign, flags);
	ft_putstr_buffer(str, save);
	return(1);
}
