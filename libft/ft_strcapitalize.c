/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 05:59:54 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/04 12:19:52 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	i = 0;
	while (str[i])
	{
		while (str[i] && !(str[i] >= 'a' && str[i] <= 'z'))
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if (str[i] == '\0')
			return (str);
	}
	return (str);
}
