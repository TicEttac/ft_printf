/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:30:43 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/17 13:40:25 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_letter(char c, char const *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s, char const *sep)
{
	size_t	len;

	if (!s)
		return (NULL);
	while (ft_check_letter(*s, sep))
		s++;
	if (!(len = ft_strlen(s)))
		return (ft_substr(s, 0, 0));
	while (ft_check_letter(s[len - 1], sep))
		len--;
	return (ft_substr(s, 0, len));
}
