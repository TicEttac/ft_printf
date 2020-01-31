/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:43:33 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/21 14:10:13 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ndst;
	unsigned char *nsrc;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	if (ndst || nsrc)
		while (n--)
			*ndst++ = *nsrc++;
	return (dst);
}
