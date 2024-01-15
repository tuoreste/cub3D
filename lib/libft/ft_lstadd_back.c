/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:48:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/17 15:22:40 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node_iter;

	node_iter = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node_iter = ft_lstlast(*lst);
	node_iter -> next = new;
}
