/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:26:45 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/25 09:44:05 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_s(va_list arg, t_flag *flags, t_buffer *save)
{
	char	*str;

	if ((ft_s_compatibility(flags)) == -1)
		return (-1);
	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	flags->point == TRUE ? str = app_precision(str, flags, 's') : 0;
	flags->width != ERROR ? str = app_width(str, 0, flags) : 0;
	ft_putstr_buffer(str, save);
	return(1);
}

int		ft_s_compatibility(t_flag *flags)
{
	if (flags->plus == TRUE)
		return (error_flag("incompatible"));
	if (flags->space == TRUE)
		return (error_flag("incompatible"));
	if (flags->zero == TRUE)
		return (error_flag("incompatible"));
	return (1);
}
