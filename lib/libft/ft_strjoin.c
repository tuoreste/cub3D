/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:57:47 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/07 11:22:05 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*c_s;
	size_t	count1;
	size_t	count2;
	size_t	count3;

	c_s = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	count1 = 0;
	count2 = 0;
	count3 = 0;
	if (!c_s)
		return (NULL);
	while (s1[count1])
	{
		c_s[count2++] = s1[count1];
		count1++;
	}
	while (s2[count3])
	{
		c_s[count2++] = s2[count3];
		count3++;
	}
	c_s[count2] = 0;
	return (c_s);
}
