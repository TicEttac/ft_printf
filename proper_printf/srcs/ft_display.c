/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:55:10 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/25 13:21:58 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			error_flag(char *bug)
{
	printf("\nError Type : %s\n", bug);
	return (-1);
}

int			display_flag(t_flag *flags)
{
	int ret;

	ret = 0;
	flags->width != ERROR ? ret += 1 : 0;
	ret *= 10;
	flags->precision != ERROR ? ret += 1 : 0;
	ret *= 10;
	flags->point != FALSE ? ret += 1 : 0;
	ret *= 10;
	ret *= 10;
	flags->space != FALSE ? ret += 1 : 0;
	ret *= 10;
	flags->zero != FALSE ? ret += 1 : 0;
	ret *= 10;
	flags->minus != FALSE ? ret += 1 : 0;
	ret *= 10;
	flags->plus != FALSE ? ret += 1 : 0;
	return ret;
}

t_flag		ft_flag_init(void)
{
	t_flag flags;

	flags.plus = FALSE;
	flags.minus = FALSE;
	flags.zero = FALSE;
	flags.space = FALSE;
	flags.point = FALSE;
	flags.precision = ERROR;
	flags.width = ERROR;
	return (flags);
}

t_buffer	ft_save_init(char const *format)
{
	t_buffer 	save;
	char 		*buffer;

	buffer = NULL;
	save.format = format;
	save.buffer = buffer;
	save.index = 0;
	save.count = 0;
	return (save);
}

int		ft_putchar_buffer(char c, t_buffer *save)
{
	if (!(ft_realloc(save)))
		return (0);
	save->buffer[save->count] = c;
	save->buffer[save->count + 1] = '\0';
	save->index++;
	save->count++;
	return (1);
}

int		ft_putstr_buffer(char *str, t_buffer *save)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_realloc(save)))
			return (0);
		save->buffer[save->count] = str[i];
		save->count++;
		save->buffer[save->count] = '\0';
		i++;
	}
	return (1);
}

int		ft_print_buffer(t_buffer *save)
{
	int i = 0;

	if (save->buffer == NULL)
		return (0);
	while (i < save->count)
	{
		write(1, &save->buffer[i], 1);
		i++;
	}
	free(save->buffer);
	return (save->count);
}

void		print_info(t_flag *flags)
{
	printf("%d", display_flag(flags));
	if (flags->width != ERROR)
		printf("__%d",  flags->width);
	if (flags->precision != ERROR)
		printf(".%d", flags->precision);
	printf("\n");
}

int		ft_realloc(t_buffer *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!(s = malloc(sizeof(char) * (save->count + 2))))
		return (0);
	while (i < save->count)
	{
		s[i] = save->buffer[i];
		i++;
	}
	s[i] = '0';
	s[i + 1] = '\0';
	free(save->buffer);
	save->buffer = s;
	return (1);
}
