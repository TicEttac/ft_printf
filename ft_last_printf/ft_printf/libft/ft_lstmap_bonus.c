/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:59:07 by mlormois          #+#    #+#             */
/*   Updated: 2019/10/21 15:19:33 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*list;
	t_list		*tmp;

	if (!lst || !f || !del)
		return (0);
	if (!(tmp = ft_lstnew(f(lst->content))))
		return (0);
	list = tmp;
	lst = lst->next;
	if (lst)
	{
		while (lst)
		{
			if (!(tmp->next = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&list, del);
				return (0);
			}
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (list);
}
