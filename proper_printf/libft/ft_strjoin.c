/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:19:43 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/15 15:24:25 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	lenstr;

	if (!s1 || !s2)
		return (0);
	lenstr = ft_strlen(s1) + ft_strlen(s2);
	if (!(s3 = malloc(sizeof(char) * (lenstr + 1))))
		return (0);
	ft_memcpy(s3, s1, lenstr + 1);
	ft_memcpy(s3 + ft_strlen(s1), s2, lenstr + 1);
	// free((void *)s1);
	// free((void *)s2);
	return (s3);
}
