/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:26:45 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/28 15:30:10 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*app_width(char *str, int sign, t_flag *flags)
{
	char *line;
	char *dst;
	char c;
	int len;

	len = 0;
	c = ' ';
	if (flags->zero == TRUE)
	{
		if (!(flags->point == TRUE && flags->precision <= (int)ft_strlen(str)))
			c = '0';
		if (flags->point == TRUE)
			sign == -1 ? sign = 0 : 0;
	}
	if (flags->zero != TRUE || (flags->zero == TRUE && flags->point == TRUE))
		sign == -1 ? sign = 0 : 0;
	if (str)
		if ((len = flags->width - ft_strlen(str) + sign) <= 0)
			return (str);
	!str ? len = flags->width - 1 : 0;
	line = ft_strnew(len, c);
	dst = flags->minus == TRUE ? ft_strjoin(str, line) : ft_strjoin(line, str);
	return (dst);
}

char	*app_precision(char *str, t_flag *flags, char type)
{
	if (type == 'd' ||  type == 'x' || type == 'u')
	{
		if (type != 'd' && flags->precision == 0 &&
				ft_strncmp(str, "0", 1) == 0)
			return ("");
		if (flags->precision <= (int)ft_strlen(str) || flags->precision == 0)
			return (str);
		return (ft_strjoin(ft_strnew(flags->precision - ft_strlen(str), '0'), str));
	}
	flags->precision == -1 ? flags->precision = 0 : 0;
	return (ft_substr(str, 0, flags->precision));
}

char	*app_signe(char *str, int sign, t_flag *flags)
 {
	char *dst;

	if (sign == -1 ? dst = ft_strnew(1, '-') : 0)
		return (ft_strjoin(dst, str));
	else
	{
		if (flags->plus == TRUE ? dst = ft_strnew(1, '+') : 0)
			return (ft_strjoin(dst, str));
		if (flags->space == TRUE ? dst = ft_strnew(1, ' ') : 0)
			return (ft_strjoin(dst, str));
	}
	return (str);
 }
