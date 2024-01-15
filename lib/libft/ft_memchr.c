/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:13:51 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/17 10:25:32 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*c_str;
	size_t			count;

	c_str = (unsigned char *)str;
	count = 0;
	while (count < n)
	{
		if (*c_str == (unsigned char)c)
		{
			return (c_str);
		}
		c_str++;
		count++;
	}
	return (NULL);
}
