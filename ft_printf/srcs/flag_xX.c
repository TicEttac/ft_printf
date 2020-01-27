/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 05:14:49 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/23 05:39:01 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_xX(va_list arg, t_flag *flags, t_buffer *save)
{
	unsigned int	x;
	char			*str;
	size_t			i;

	i = 0;
	x = (unsigned int)va_arg(arg, unsigned int);
	str = ft_utoa_base(x, 16);
	if (save->format[save->index - 1] == 'X')
		str = ft_strcapitalize(str);
	flags->precision != ERROR ? str = app_precision(str, flags, 'x') : 0;
	flags->width != ERROR ? str = app_width(str, 0, flags) : 0;
	ft_putstr_buffer(str, save);
	return (1);
}
