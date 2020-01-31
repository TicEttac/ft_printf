/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 06:24:43 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/25 09:37:48 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_mod(va_list arg, t_flag *flags, t_buffer *save)
{
	(void)arg;
	if (flags->plus || flags->minus || flags->zero || flags->space
			|| flags->width != ERROR || flags->precision != ERROR)
		return (error_flag("flags"));
	ft_putstr_buffer("%", save);
	return (1);
}
