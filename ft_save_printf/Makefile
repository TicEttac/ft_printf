# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 11:50:47 by nisauvig          #+#    #+#              #
#    Updated: 2020/01/27 03:37:54 by nisauvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =		ft_printf.c			\
			ft_display.c 		\
			parsing.c			\
			parsing_ext.c		\
			flag_s.c			\
			flag_c.c 			\
			flag_mod.c			\
			flag_p.c			\
			flag_u.c			\
			flag_xX.c			\
			flag_di.c 			\
			line_utils.c 		\

LIB_SRCS=	ft_atoi.c 			\
			ft_bzero.c 			\
			ft_calloc.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memalloc.c 		\
			ft_memset.c			\
			ft_putchar.c		\
			ft_putnbr.c			\
			ft_putstr.c			\
			ft_putchar_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c		\
			ft_split.c			\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strncpy.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strnew.c 		\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strtrim.c		\
			ft_substr.c			\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_itoa_base.c		\
			ft_utoa_base.c		\
			ft_strcapitalize.c	\
			ft_rev_char_tab.c	\

OBJS = $(addprefix srcs/, $(SRCS:.c=.o))
LIB_OBJS = $(addprefix libft/, $(LIB_SRCS:.c=.o))

CFLAGS = -Wall -Werror -Wextra -g
CC = gcc
LIB = libft/libft.a
INC = ./libftprintf.h

all:	$(NAME)

$(NAME): $(OBJS)
	@Rm -rf ./objs
	@mkdir ./objs
	@make -C ./libft all
	@ar -rcs ${NAME} ${OBJS} ${LIB_OBJS} #&& printf "%-60b\r" "$(_GREEN)$(ECHO)$(_CYAN) Compilation $@"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@Rm -rf ./objs
	@make -C libft clean
	@Rm -rf ${OBJS}

fclean:
	@rm -rf ./objs
	@make -C libft fclean
	@rm -f $(NAME)
	@Rm -rf ${OBJS}
	@rm -rf auteur

re: fclean all

git: fclean
	@git add .
	@git commit -m "$@"
	@git push

.PHONY: all clean fclean re
