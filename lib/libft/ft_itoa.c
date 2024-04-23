/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:08:12 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/17 11:16:55 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_absolute_no(int no);

static int	ft_count_digits(int n);

char	*ft_itoa(int n)
{
	int		n_digits;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_digits = ft_count_digits(n);
	str = (char *)malloc((n_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[n_digits] = '\0';
	if (n < 0)
	{
		str[0] = '-';
	}
	while (n && n_digits--)
	{
		str[n_digits] = ft_absolute_no(n % 10) + '0';
		n = (n / 10);
	}
	return (str);
}

static int	ft_absolute_no(int no)
{
	if (no < 0)
		return (-no);
	return (no);
}

static int	ft_count_digits(int n)
{
	int	count_digits;
	int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		count_digits = 1;
	}
	else
		count_digits = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		count_digits++;
	}
	return (count_digits);
}
