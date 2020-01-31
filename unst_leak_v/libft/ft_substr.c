/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:58:20 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/30 11:42:25 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (0);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	while (len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
