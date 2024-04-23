/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:30:07 by aguediri          #+#    #+#             */
/*   Updated: 2024/03/21 17:10:55 by otuyishi         ###   ########.fr       */
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
	while (s[last_line_index][j++])
	{
		if (s[last_line_index][j] == ' ' || s[last_line_index][j] == '\t')
		{
			while (s[i][j] == ' ' || s[i][j] == '\t')
				i--;
			if (s[i][j] == '0')
				return (free(str), 0);
			i = last_line_index;
		}
	}
	return (free(str), 1);
}

void	frees(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
}

int	checkmap(t_map *data)
{
	data->temp.i = 0;
	data->temp.r = 1;
	data->temp.u = 0;
	data->temp.r = checkfirstline(data->map);
	if (data->temp.r)
		data->temp.r = checklastline(data->map);
	while (data->map[data->temp.i])
	{
		data->temp.s4 = ft_strtrim(data->map[data->temp.i], "01 \tNSWE");
		data->temp.s2 = ft_strtrim(data->map[data->temp.i], "01 \t");
		if (ft_strlen(data->temp.s4) != ft_strlen(data->temp.s2))
			data->temp.u++;
		if (ft_strlen(data->temp.s4) || !checkh(data->map[data->temp.i]))
			return (free(data->temp.s2), free(data->temp.s4), 0);
		data->temp.s1 = ft_strtrim(data->map[data->temp.i], " \t");
		if (data->temp.s1[ft_strlen(data->temp.s1) - 1] != '1'
			|| data->temp.s1[0] != '1')
			return (frees(data->temp.s1, data->temp.s2, data->temp.s4), 0);
		frees(data->temp.s1, data->temp.s2, data->temp.s4);
		data->temp.i++;
	}
	if (data->temp.u != 1)
		return (0);
	return (data->temp.r);
}
