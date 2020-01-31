/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 03:28:57 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/10 04:14:47 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *dest;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	if (!(dest = malloc(count * size)))
		return (0);
	ft_bzero(dest, (count * size));
	return (dest);
}

