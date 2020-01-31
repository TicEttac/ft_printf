/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 05:52:51 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/25 00:51:28 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_precision_star(va_list arg, t_buffer *save, t_flag *flags)
{
	t_flag	tmp;

	tmp = *flags;
	flags->point = TRUE;
	if (save->format[save->index] == '*' ? save->index++ : 0)
	{
		flags->precision = va_arg(arg, int);
		if (flags->precision < 0)
		{
			*flags = ft_flag_init();
			flags->width = tmp.width;
			flags->minus = tmp.minus;
			flags->zero = tmp.zero;
		}
		return (1);
	}
	return (0);
}

int		ft_width_star(va_list arg, t_buffer *save, t_flag *flags)
{
	t_flag	tmp;

	if (save->format[save->index] == '*' ? save->index++ : 0)
	{
		flags->width = va_arg(arg, int);
		if (flags->width < 0 ? flags->width *= -1 : 0)
		{
			tmp = *flags;
			*flags = ft_flag_init();
			flags->width = tmp.width;
			flags->point = tmp.point;
			flags->minus = TRUE;
		}
		return (1);
	}
	return (0);
}
