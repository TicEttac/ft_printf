/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:52:23 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/17 16:05:36 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *lsd;

	lsd = 0;
	if (*s == (char)c)
		lsd = s;
	while (*s++)
		if (*s == (char)c)
			lsd = s;
	return ((char *)lsd);
}
