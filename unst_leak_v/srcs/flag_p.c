/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 12:31:34 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/30 13:47:16 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//#include <stdio.h>
//#include <stdlib.h>

char	*ft_ultoa_base(unsigned long value, int base)
{
	char	*tab_base;
	char	*dst;
	int		size_dst;
	int		valtmp;
	int		i;

	size_dst = 1;
	valtmp = value;
	tab_base = "0123456789abcdef";
	while (valtmp ? valtmp /= base : 0)
		size_dst++;
	if (!(dst = (char *)malloc(sizeof(char) * (size_dst + 1))))
		return (NULL);
	i = 1;
	while (value != 0 ? dst[size_dst - i++] = tab_base[value % base] : 0)
		value /= base;
	dst[size_dst] = '\0';
	return (dst);
}

int		flag_p(va_list arg, t_flag *flags, t_buffer *save)
{
	char			*res;
	unsigned long	tmp;

	tmp = (unsigned long)va_arg(arg, unsigned long);
	if (!(res = ft_utoa_base(tmp, 16)))
		return (ERROR);
	if (flags->plus || flags->zero || flags->space
			|| flags->point || flags->precision != ERROR)
		return (ERROR);
	res = ft_joinfree("0x", res, 2);
	flags->width ? res = app_width(res, 0, flags) : 0;
	ft_putstr_buffer(res, save);
	free(res);
	return (1);
}
