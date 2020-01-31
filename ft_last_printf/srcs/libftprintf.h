/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:26:24 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/25 13:31:51 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define DIFFLETTER 32
# define DIFFASCII 48
# define ERROR -1
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdbool.h>

# include "../libft/libft.h"

# define C {'c', &flag_c}
# define S {'s', &flag_s}
# define P {'p', &flag_p}
# define D {'d', &flag_di}
# define I {'i', &flag_di}
# define U {'u', &flag_u}
# define X {'x', &flag_xX}
# define XX {'X', &flag_xX}
# define MOD {'%', &flag_mod}

typedef struct	s_flag
{
	bool		plus;
	bool		minus;
	bool		zero;
	bool 		space;
	int			width;
	bool		point;
	int			precision;
}				t_flag;

typedef struct 	s_buffer
{
	char const	*format;
	char 		*buffer;
	int 		index;
	int			count;
}				t_buffer;

typedef struct	s_type
{
	char		type;
	int			(*func)(va_list arg, t_flag *size, t_buffer *save);
}				t_type;

int				ft_printf(char const *format, ...);
int				ft_vprintf(char const *format, va_list arg);

int				ft_putchar_buffer(char c, t_buffer *save);
int				ft_putstr_buffer(char *str, t_buffer *save);
int				ft_print_buffer(t_buffer *save);

int				ft_realloc(t_buffer *save);

int				ft_parsing(va_list arg, t_buffer *save);
void			ft_parsing_flag(t_buffer *save, t_flag *flags);
int				ft_width(va_list arg, t_buffer *save, t_flag *flags);
int				ft_width_star(va_list arg, t_buffer *save, t_flag *flags);
int				ft_precision(va_list arg, t_buffer *save, t_flag *flags);
int				ft_precision_star(va_list arg, t_buffer *save, t_flag *flags);

char			*app_precision(char *str, t_flag *flags, char type);
char			*app_width(char *str, int sign, t_flag *flags);
char			*app_signe(char *str, int sign, t_flag *flags);

int				flag_c(va_list arg, t_flag *flags, t_buffer *save);
int				flag_s(va_list arg, t_flag *flags, t_buffer *save);
int				flag_p(va_list arg, t_flag *flags, t_buffer *save);
int				flag_di(va_list arg, t_flag *flags, t_buffer *save);
int				flag_u(va_list arg, t_flag *flags, t_buffer *save);
int				flag_xX(va_list arg, t_flag *flags, t_buffer *save);
int				flag_mod(va_list arg, t_flag *flags, t_buffer *save);

int				error_flag(char *bug);
int				display_flag(t_flag *flags);
void			print_info(t_flag *flags);

t_flag			ft_flag_init(void);
t_buffer		ft_save_init(char const *format);

int				ft_s_compatibility(t_flag *flags);
int				ft_c_compatibility(t_flag *flags);

char			*ft_ultoa(unsigned int i);

#endif
