#include <stdio.h>
#include "srcs/libftprintf.h"

int main()
{
	void *s;
	printf(" [%d]\n", ft_printf("|%p|", s));
	printf(" [%d]\n", printf("|%p|", s));
	return 0;
}
