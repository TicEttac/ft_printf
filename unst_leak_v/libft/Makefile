SRCS=	ft_atoi.c 			\
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
		ft_joinfree.c		\

BONUS=	ft_lstnew_bonus.c			\
		ft_lstsize_bonus.c			\
		ft_lstlast_bonus.c			\
		ft_lstadd_front_bonus.c		\
		ft_lstadd_back_bonus.c		\
		ft_lstdelone_bonus.c		\
		ft_lstiter_bonus.c			\
		ft_lstclear_bonus.c			\
		ft_lstmap_bonus.c			\

OBJS= ${SRCS:.c=.o}
OBJS_BONUS= ${BONUS:.c=.o}

T = $(words $(OBJS)$(OBJS_BONUS) 0)
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C '*' 100 / $T`%]"

_CYAN  = \033[36m
_GREEN = \033[32m
_RED   = \033[31m
_ENDL  = \033[0m

CFLAGS= -Wall -Werror -Wextra
CC= gcc
NAME= libft.a

all: ${NAME}

$(NAME):	${}${OBJS}
			@ar -rc ${NAME} $^ && echo "$(_GREEN)[100%] LIBFT Compilation Success            $(_ENDL)"
			@ranlib ${NAME}

%.o: %.c
			@${CC} ${CFLAGS} -o $@ -c $<
			@printf "%-60b\r" "$(_GREEN)$(ECHO)$(_CYAN) Compilation $@"

bonus:		${OBJS} ${OBJS_BONUS}
			@ar -rc ${NAME} $^ && echo "$(_GREEN)[100%] LIBFT Bonus Compilation Success     $(_ENDL)"
			@ranlib ${NAME}

clean:
			@rm -f ${OBJS} ${OBJS_BONUS} && echo "$(_RED)[100%]$(_CYAN)  files.o has been cleaned"

fclean: clean
			@rm -f ${NAME} && echo "$(_RED)libft.a $(_CYAN)        has been cleaned"

re: fclean all

.PHONY: all bonus clean fclean re
