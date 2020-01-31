/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:01:27 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/17 15:58:41 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	lsrc;

	if (!dest || !src)
		return (0);
	lsrc = ft_strlen(src);
	if (lsrc + 1 < size)
		ft_memcpy(dest, src, lsrc + 1);
	else
	{
		if (size)
		{
			ft_memcpy(dest, src, size - 1);
			dest[size - 1] = '\0';
		}
	}
	return (lsrc);
}
