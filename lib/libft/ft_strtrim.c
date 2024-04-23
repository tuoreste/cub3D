/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:29:56 by otuyishi          #+#    #+#             */
/*   Updated: 2024/01/21 18:10:23 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	s1_len;
	char	*c_s1;

	count = 0;
	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	c_s1 = NULL;
	if (s1 != 0 && set != 0)
	{
		while (s1[count] && ft_strchr(set, s1[count]))
		{
			count++;
		}
		while (s1[s1_len - 1] && ft_strchr(set, s1[s1_len - 1])
			&& s1_len > count)
		{
			s1_len--;
		}
		c_s1 = (char *)malloc(sizeof(char) * (s1_len - count + 1));
		if (c_s1)
			ft_strlcpy(c_s1, &s1[count], s1_len - count + 1);
	}
	return (c_s1);
}
