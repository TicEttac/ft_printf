/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:27:17 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/25 09:16:23 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parsing(va_list arg, t_buffer *save)
{
	static t_type	tab[] = {C, S, P, D, I, U, X, XX, MOD};
	t_flag			flags;
	size_t			i;

	i = 0;
	flags = ft_flag_init();
	ft_parsing_flag(save, &flags);
	if ((ft_width(arg, save, &flags)) == -1)
		return (error_flag("Taille de Champs"));
	if (save->format[save->index] == '.' ? save->index++ : 0)
		if ((ft_precision(arg, save, &flags)) == -1)
			return (error_flag("Precision"));
	while (i < sizeof(tab) / sizeof(*tab))
	{
		if ((save->format[save->index] == tab[i].type) ? save->index++ : 0)
			return (tab[i].func(arg, &flags, save));
		i++;
	}
	return (error_flag("Format Invalide"));
}

void	ft_parsing_flag(t_buffer *save, t_flag *flags)
{
	while (save->format[save->index] == '+' || save->format[save->index] == '-'
	|| save->format[save->index] == ' ' || save->format[save->index] == '0')
	{
		if (save->format[save->index] == '+' ? flags->plus = TRUE : 0)
			flags->space == TRUE ? flags->space = FALSE : 0;
		if (save->format[save->index] == '-' ? flags->minus = TRUE : 0)
			flags->zero == TRUE ? flags->zero = FALSE : 0;
		if (save->format[save->index] == ' ' ? flags->space = TRUE : 0)
			flags->plus == TRUE ? flags->space = FALSE : 0;
		if (save->format[save->index] == '0' ? flags->zero = TRUE : 0)
			flags->minus == TRUE ? flags->zero = FALSE : 0;
		save->index++;
	}
}

int		ft_width(va_list arg, t_buffer *save, t_flag *flags)
{
	if (ft_width_star(arg, save, flags) == 1)
		return (1);
	if (ft_isdigit(save->format[save->index]))
	{
		flags->width = 0;
		while (ft_isdigit(save->format[save->index]))
		{
			flags->width *= 10;
			flags->width += save->format[save->index] - DIFFASCII;
			save->index++;
		}
	}
	return (1);
}

int		ft_precision(va_list arg, t_buffer *save, t_flag *flags)
{
	if (ft_precision_star(arg, save, flags) == TRUE)
		return (1);
	if (ft_isdigit(save->format[save->index]))
	{
		flags->precision = 0;
		while (ft_isdigit(save->format[save->index]))
		{
			flags->precision *= 10;
			flags->precision += save->format[save->index] - DIFFASCII;
			save->index++;
		}
	}
	return (1);
}
