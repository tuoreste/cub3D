/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:41:42 by otuyishi          #+#    #+#             */
/*   Updated: 2023/04/08 15:40:08 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*c_s;

	count = 0;
	c_s = (char *)malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (c_s == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		c_s[count] = f(count, s[count]);
		count++;
	}
	c_s[count] = '\0';
	return (c_s);
}
