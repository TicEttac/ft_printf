#include <stdio.h>
#include "srcs/libftprintf.h"

int main()
{
	ft_printf("mine [%-5.2d]\n", 799);
	printf("true [%-5.2d]\n", 799);
	printf("true [%2.3u]\n", -2);
	ft_printf("mine [%2.3u]\n", -2);
}
