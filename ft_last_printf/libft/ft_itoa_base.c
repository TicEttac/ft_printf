/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 00:27:40 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/17 17:10:21 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char	*tab_base;
	char	*dst;
	int		size_dst;
	int		sign;
	int		i;

	sign = 0;
	if (base < 2 || base > 16)
		return ("error\n");
	if (value < 0 ? sign = 1 : 0)
		value = -value;
	tab_base = "0123456789abcdef";
	size_dst = digit_count(value, base);
	size_dst += (sign ? 1 : 0);
	dst = (char *)malloc(sizeof(char) * (size_dst + 1));
	i = 1;
	sign ? (dst[0] = '-') : 0;
	while (value != 0 ? dst[size_dst - i++] = tab_base[value % base] : 0)
		value /= base;
	dst[size_dst] = '\0';
	return (dst);
}

int		digit_count(long nb, int base)
{
	int i;

	i = 1;
	while (nb ? nb /= base : 0)
		i++;
	return (i);
}
