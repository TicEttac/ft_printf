/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tempstrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:44:51 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/28 14:48:09 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	if (!(s3 = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	if (s1)
		ft_memcpy(s3, s1, len1 + 1);
	if (s1 && s2)
		ft_memcpy(s3 + ft_strlen(s1), s2, len2 + 1);
	else if (s2)
		ft_memcpy(s3, s2, len2 + 1);
	return (s3);
}
