/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:30:07 by aguediri          #+#    #+#             */
/*   Updated: 2024/03/20 22:51:38 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checkh(char *s)
{
	int	i;

	i = 1;
	while (s[i + 1])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			if (s[i - 1] == '0' || s[i + 1] == '0')
				return (0);
		}
		i++;
	}
	return (1);
}

int	checkfirstline(char **s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strtrim(s[0], "1 \t");
	if (ft_strlen(str))
		return (free(str), 0);
	while (s[0][j])
	{
		if (s[0][j] == ' ' || s[0][j] == '\t')
		{
			while (s[i][j] == ' ' || s[i][j] == '\t')
				i++;
			if (s[i][j] == '0')
				return (0);
			i = 0;
		}
		j++;
	}
	free(str);
	return (1);
}

int	checklastline(char **s)
{
	int		i;
	int		j;
	int		last_line_index;
	char	*str;

	j = 0;
	last_line_index = 0;
	while (s[last_line_index + 1] != NULL)
		last_line_index++;
	i = last_line_index;
	str = ft_strtrim(s[last_line_index], "1 \t");
	if (ft_strlen(str))
		return (free(str), 0);
	while (s[last_line_index][j])
	{
		if (s[last_line_index][j] == ' ' || s[last_line_index][j] == '\t')
		{
			while (s[i][j] == ' ' || s[i][j] == '\t')
				i--;
			if (s[i][j] == '0')
				return (free(str), 0);
			i = last_line_index;
		}
		j++;
	}
	return (free(str), 1);
}

// ===================================PROBLEM 1===========================
int	checkmap(t_map *data)
{
	int		i;
	int		r;
	int		u;
	char	*s1;
	char	*s2;
	// char	*s3;
	char	*s4;

	i = 0;
	r = 1;
	u = 0;
	if (ft_strlen(data->map[0]) == 0)
		return (0);
	r = checkfirstline(data->map);
	if (r)
		r = checklastline(data->map);
	while (data->map[i])
	{
		s4 = ft_strtrim(data->map[i], "01 \tNSWE");
		s2 = ft_strtrim(data->map[i],"01 \t");
		if (ft_strlen(s4) != ft_strlen(s2))
			u++;
		if (ft_strlen(s4) || !checkh(data->map[i]))
			return (free(s2), free(s4), 0);
		s1 = ft_strtrim(data->map[i], " \t");
		if (s1[ft_strlen(s1) - 1] != '1' || s1[0] != '1')
			return (free(s1), free(s2), free(s4), 0);
		i++;
	}
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	// s3 = ft_strtrim(data->map[i - 1], " 1\t");
	// if (ft_strlen(s3))
	// 	return (free(s3), 0);
	if (u != 1)
		return (0);
	return (r);
}
// ===================================PROBLEM 1===========================