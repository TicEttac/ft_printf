/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:10:22 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/21 14:17:11 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long i;
	unsigned long j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && len > i + j++)
			if (!needle[j])
				return ((char *)haystack + i);
		i++;
	}
	return (0);
}
