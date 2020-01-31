/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:42:39 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/21 14:24:54 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbstr(const char *s, char c)
{
	int nb;

	nb = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			nb++;
			while (*s && *s != c)
				s++;
		}
	}
	return (nb);
}

static char		*ft_malloc_str(char const *str, char c)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_memcpy(dst, str, i);
	dst[i] = '\0';
	return (dst);
}

static char		**ft_reset(char **strs, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	int		nbstr;
	int		i;

	if (!s)
		return (0);
	nbstr = ft_nbstr(s, c);
	if (!(strs = (char **)malloc(sizeof(char *) * (nbstr + 1))))
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(strs[i] = ft_malloc_str(s, c)))
				return (ft_reset(strs, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	strs[i] = 0;
	return (strs);
}
