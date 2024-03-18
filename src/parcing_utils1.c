/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:01:11 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/18 15:10:51 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*manage_data(char *s)
{
	int		i;
	t_map	*data;
	char	**t;
	char	**t1;
	char	*map;
	char	*temp;

	data = (t_map *)malloc(sizeof(t_map));
	map = "";
	i = 0;
	t = ft_split(s, '\n');
	while (t[i])
	{
		temp = ft_strtrim(t[i], " \t012NSWE");
		if (ft_strnstr(t[i], "NO", 2) || ft_strnstr(t[i], "SO", 2)
			|| ft_strnstr(t[i], "WE", 2) || ft_strnstr(t[i], "EA", 2))
			manage_directions(t[i], data);
		else if (ft_strnstr(t[i], "S", 1) || ft_strnstr(t[i], "C", 1)
			|| ft_strnstr(t[i], "F", 1))
			manage_sfc(t[i], data);
		else if (ft_strnstr(t[i], "S", 1))
		{
			t1 = ft_split(t[i], ' ');
			data->h = ft_atoi(t1[1]);
			data->w = ft_atoi(t1[2]);
			free_split(t1);
		}
		else if (ft_strlen(temp) == 0)
		{
			map = ft_strjoin(map, t[i]);
			map = ft_strjoin(map, "\n");
		}
		free (temp);
		i++;
	}
	free_split(t);
	data->map = ft_split(map, '\n');
	free(map);
	getmapcord(data);
	if (!data->c)
		data->c = ft_strdup("163,208,230");
	if (!data->f)
		data->f = ft_strdup("163,208,230");
	return (data);
}

t_map	*get_map_data(char *s)
{
	int		fd;
	char	*line;
	char	*str;
	t_map	*data;

	fd = open(s, O_RDONLY);
	str = "";
	data = NULL;
	if (!fd)
	{
		perror("Error opening file");
		return (NULL);
	}
	line = get_next_line(fd);
	while ((line) != NULL)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data = manage_data(str);
	free(str);
	return (data);
}
