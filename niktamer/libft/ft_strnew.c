/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:08:00 by mlormois          #+#    #+#             */
/*   Updated: 2020/01/07 01:16:38 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size, char c)
{
	char	*str;
	char	*res;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	res = str;
	str[size] = '\0';
	while ((int)size-- > 0)
		*str++ = c;
	return (res);
}
