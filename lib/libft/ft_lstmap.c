/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:49:09 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/17 22:36:41 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_safer(void *content)
{
	t_list	*node_one;

	node_one = (t_list *)malloc(sizeof(t_list));
	if (node_one == NULL)
	{
		free(content);
		return (NULL);
	}
	node_one -> content = content;
	node_one -> next = NULL;
	return (node_one);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_two;
	t_list	*current_node;

	lst_two = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		current_node = ft_lstnew_safer((*f)(lst->content));
		if (current_node == NULL)
		{
			ft_lstclear(&lst_two, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_two, current_node);
		lst = lst -> next;
	}
	return (lst_two);
}
