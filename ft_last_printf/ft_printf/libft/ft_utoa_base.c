/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:10:09 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/25 09:16:00 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sizing(unsigned int tmp_val, int base)
{
	int				size_dst;

	size_dst = 0;
	while (tmp_val)
	{
		tmp_val /= base;
		size_dst++;
	}
	return (size_dst);
}

char	*ft_utoa_base(unsigned int value, int base)
{
	char	*tab_base;
	char	*dst;
	int		size_dst;
	int		i;

	if (value == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return ("error\n");
	tab_base = "0123456789abcdef";
	size_dst = sizing(value, base);
	if (!(dst = (char *)malloc(sizeof(char) * (size_dst + 1))))
		return (NULL);
	i = 1;
	while (value)
	{
		dst[size_dst - i++] = tab_base[value % base];
		value /= base;
	}
	dst[size_dst] = '\0';
	return (dst);
}
