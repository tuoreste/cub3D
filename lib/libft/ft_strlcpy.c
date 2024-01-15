/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:00:44 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/05 17:18:07 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len_dst)
{
	size_t	len_src;
	char	*src_src;

	src_src = (char *)src;
	len_src = ft_strlen(src_src);
	if (len_dst == 0)
	{
		return (len_src);
	}
	else if (len_src < len_dst)
	{
		ft_memcpy(dst, src, len_src + 1);
	}
	else
	{
		ft_memcpy(dst, src, len_dst - 1);
		dst[len_dst - 1] = '\0';
	}
	return (len_src);
}
