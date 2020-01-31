/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 08:32:50 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/30 08:59:59 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *s1, char *s2, int i)
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
	if (s1 && (i == 1 || i == 3))
		free(s1);
	if (s2 && (i == 2 || i == 3))
		free(s2);
	return (s3);
}
