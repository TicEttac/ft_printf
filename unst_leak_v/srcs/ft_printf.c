/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 05:46:25 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/31 02:22:19 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		ft_printf(char const *format, ...)
{
	va_list		argv;
	int			done;

	va_start(argv, format);
	done = ft_vprintf(format, argv);
	va_end(argv);
	return (done);
}

int		ft_vprintf(char const *format, va_list arg)
{
	t_buffer	save;

//	save = ft_save_init(format);
	ft_memset(&save, 0, sizeof(t_buffer));
	save.format = format;
	while (save.format[save.index])
	{
		if (save.format[save.index] == '%')
		{
			save.index++;
			if (ft_parsing(arg, &save) == -1)
				return (error_flag("Wrong Parsing"));
		}
		else
			ft_putchar_buffer(save.format[save.index], &save);
	}
	return (ft_print_buffer(&save));
}
