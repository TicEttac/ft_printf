/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:52:43 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/16 17:04:02 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newlist;

	if (!(newlist = malloc(sizeof(t_list))))
		return (0);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
