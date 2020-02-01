/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:59:04 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/11 17:17:01 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	i;
	int		flag;
	long	nb;

	i = 0;
	nb = 0;
	flag = 1;
	while (str[i] == '\r' || str[i] == '\t' || str[i] == '\f' ||
			str[i] == '\v' || str[i] == '\n' || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb *= 10;
		nb += str[i] - DIFFASCII;
		i++;
	}
	return (nb * flag);
}
