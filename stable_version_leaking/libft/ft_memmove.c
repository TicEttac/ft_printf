/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:54:24 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/21 14:14:44 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ndst;
	char		*lastd;
	char		*lasts;
	char		*nsrc;

	ndst = dst;
	nsrc = (char *)src;
	if (ndst <= nsrc)
		return (ft_memcpy(dst, src, len));
	else
	{
		lastd = ndst + (len - 1);
		lasts = nsrc + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}
