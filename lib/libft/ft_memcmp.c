/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:13:53 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/13 21:20:48 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s11;
	const unsigned char		*s22;
	size_t					count;

	s11 = (const unsigned char *) s1;
	s22 = (const unsigned char *) s2;
	count = 0;
	while (count < n)
	{
		if (s11[count] != s22[count])
			return (s11[count] - s22[count]);
		count++;
	}
	return (0);
}
