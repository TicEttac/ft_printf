/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:39:16 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/04 14:46:54 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(long n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_len_int(nb);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = 0 + DIFFASCII;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + DIFFASCII;
		nb = nb / 10;
	}
	return (str);
}
