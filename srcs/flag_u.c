/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:22:24 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/29 02:47:44 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_u(va_list arg, t_flag *flags, t_buffer *save)
{
	unsigned int	i;
	char			*tmp;
	char			*res;

	i = va_arg(arg, unsigned int);
	if (flags->plus || flags->space)
		return (ERROR);
	if (i == 0 && (flags->precision == 0 || (flags->point == TRUE
					&& flags->precision == ERROR)))
		res = ft_strdup(" ");
	else
		res = ft_utoa_base(i, 10);
	if (flags->precision != ERROR ? tmp = app_precision(res, flags, 'u') : 0)
	{
		free(res);
		res = tmp;
	}
	if (flags->width != ERROR ? tmp = app_width(res, 0, flags) : 0)
		free(res);
	tmp ? ft_putstr_buffer(tmp, save) : ft_putstr_buffer(res, save);
	return (1);
}
