/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:19:30 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/05 17:17:48 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	i = 0;
	while (dst[dst_len] && dst_len < dst_size)
	{
		dst_len++;
	}
	while (src[i] && dst_len + i + 1 < dst_size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < dst_size)
	{
		dst[dst_len + i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (dst_len + i);
}
