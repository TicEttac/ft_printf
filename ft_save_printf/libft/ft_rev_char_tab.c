/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_char_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:26:43 by nisauvig          #+#    #+#             */
/*   Updated: 2020/01/04 14:46:58 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_rev_char_tab(char *tab)
{
	int i;
	int j;
	char tmp;

	i = 0;
	j = ft_strlen(tab) - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i++] = tab[j];
		tab[j--] = tmp;
	}
}
