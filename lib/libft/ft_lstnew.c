/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:33:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/15 13:08:27 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node_one;

	node_one = (t_list *)malloc(sizeof(t_list));
	if (node_one == NULL)
		return (NULL);
	node_one -> content = content;
	node_one -> next = NULL;
	return (node_one);
}
