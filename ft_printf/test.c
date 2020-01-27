#include <stdio.h>

#include "srcs/libftprintf.h"

int main()
{
	int a = 8;
	int b = 0;
		char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";

	printf(" --- daret[%d]\n", printf("[!%38c!]", 'd'));
	printf(" --- myret[%d]\n", ft_printf("[!%38c!]", 'd'));

}
