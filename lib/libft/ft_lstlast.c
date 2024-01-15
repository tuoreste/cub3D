/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:37:39 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/15 13:45:20 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;
	int	iter;

	size = ft_lstsize(lst);
	iter = 0;
	if (lst == NULL)
		return (lst);
	while (iter < size - 1)
	{
		iter++;
		lst = lst -> next;
	}
	return (lst);
}
