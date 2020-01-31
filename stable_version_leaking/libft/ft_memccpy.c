/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:20:17 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/21 14:11:14 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*p;
	int		newn;

	p = ft_memchr(src, c, n);
	if (p)
	{
		newn = p - src + 1;
		return (ft_memcpy(dst, src, newn) + newn);
	}
	ft_memcpy(dst, src, n);
	return (0);
}
