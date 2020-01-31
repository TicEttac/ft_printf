/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:45:32 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/21 14:12:14 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ldst;
	size_t lsrc;

	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	if (ldst >= size)
		return (lsrc + size);
	if (lsrc < size - ldst)
		ft_memcpy(dst + ldst, src, lsrc + 1);
	else
	{
		ft_memcpy(dst + ldst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (ldst + lsrc);
}
