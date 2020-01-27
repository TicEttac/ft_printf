/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:48:22 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/26 20:00:27 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*nstr;
	unsigned char	x;
	size_t			i;

	i = 0;
	x = (unsigned char)c;
	nstr = (unsigned char *)s;
	while (i < n)
	{
		if (nstr[i] == x)
			return (&nstr[i]);
		i++;
	}
	return (0);
}
