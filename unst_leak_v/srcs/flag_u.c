/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:22:24 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:14 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_u(va_list arg, t_flag *flags, t_buffer *save)
{
	unsigned int	i;
	char				*res;

	i = va_arg(arg, unsigned int);
	if (flags->plus || flags->space)
		return (ERROR);
	res = ft_utoa_base(i, 10);
	flags->precision != ERROR ? res = app_precision(res, flags, 'u'): 0;
	if (i == 0 && flags->zero == TRUE && flags->point == TRUE
			&& (flags->precision == 0 || flags->precision == ERROR))
		res = flags->width != ERROR ? res = app_width(NULL, 0, flags) : ft_strdup("");
	else
		flags->width != ERROR ? res = app_width(res, 0, flags) : 0;
	ft_putstr_buffer(res, save);
//	free(res);
	return (1);
}
