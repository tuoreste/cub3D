/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:49:08 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/16 16:48:26 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst_dst;
	const char		*src_src;
	size_t			count;

	dst_dst = (char *)dst;
	src_src = (const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src_src <= dst_dst)
	{
		count = len;
		while (count--)
			*(dst_dst + count) = *(src_src + count);
	}
	else
	{
		count = 0;
		while (count < len)
		{
			*(dst_dst + count) = *(src_src + count);
			count++;
		}
	}
	return (dst);
}
