/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:58:06 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/23 05:59:15 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ls1;
	const unsigned char *ls2;

	ls1 = (unsigned char *)s1;
	ls2 = (unsigned char *)s2;
	while (n--)
		if (*ls1++ != *ls2++)
			return (*--ls1 - *--ls2);
	return (0);
}
