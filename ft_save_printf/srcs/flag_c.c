/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:26:45 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/28 19:05:44 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_bzero_buffer(t_buffer *save)
{
	char	*s;

	s = NULL;
	if (!(s = malloc(save->count + 2)))
		return (0);
	ft_memcpy(s, save->buffer, save->count);
	save->count++;
	s[save->count] = '\0';
	if (save->buffer)
	{
		free(save->buffer);
		save->buffer = NULL;
	}
	save->buffer = ft_strdup(s);
	free(s);
	return (1);
}


int		flag_c(va_list arg, t_flag *flags, t_buffer *save)
{
	char	c;
	char	*str;

	str = NULL;
	if (ft_c_compatibility(flags) == -1)
		return (-1);
	c = va_arg(arg, int);
	if (c == (char)0)
	{
		if (flags->minus == TRUE && !(ft_bzero_buffer(save)))
			return (-1);
		if (flags->width != -1 ? str = app_width(str, 0, flags) : 0)
			ft_putstr_buffer(str, save);
		if (flags->minus == FALSE && !ft_bzero_buffer(save))
			return (-1);
		return (1);
	}
	str = ft_strnew(2, 0);
	str[0] = c;
	flags->width != -1 ? str = app_width(str, 0, flags) : 0;
	ft_putstr_buffer(str, save);
	return(1);
}

int		ft_c_compatibility(t_flag *flags)
{
	if (flags->plus == TRUE)
		return (error_flag("incompatible"));
	if (flags->space == TRUE)
		return (error_flag("incompatible"));
	if (flags->zero == TRUE)
		return (error_flag("incompatible"));
	if (flags->point == TRUE)
		return (error_flag("incompatible"));
	return (1);
}
