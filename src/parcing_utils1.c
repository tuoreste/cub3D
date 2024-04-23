/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:01:11 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/21 17:42:09 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cf_code(t_map *data)
{
	free_split(data->temp.t);
	data->map = ft_split(data->temp.map, '\n');
	free(data->temp.map);
	getmapcord(data);
	if (!data->c)
		data->c = ft_strdup("163,208,230");
	if (!data->f)
		data->f = ft_strdup("163,208,230");
}

void	manage_data(char *s, t_map *data)
{
	data->temp.i = 0;
	data->temp.map = ft_strdup("");
	data->temp.t = ft_split(s, '\n');
	while (data->temp.t[data->temp.i])
	{
		data->temp.tmp = ft_strtrim(data->temp.t[data->temp.i], " \t012NSWE");
		if (compass(data->temp.t[data->temp.i]) == 2)
			manage_directions(data->temp.t[data->temp.i], data);
		else if (compass(data->temp.t[data->temp.i]) == 3)
			manage_sfc(data->temp.t[data->temp.i], data);
		else if (ft_strlen(data->temp.tmp) == 0)
		{
			data->temp.tmp_map = ft_strjoin(data->temp.map,
					data->temp.t[data->temp.i]);
			if (!data->temp.tmp_map)
				return (free_split(data->temp.t), free(data->temp.map));
			free(data->temp.map);
			data->temp.map = data->temp.tmp_map;
			data->temp.map = ft_strjoin(data->temp.map, "\n");
			free(data->temp.tmp_map);
		}
		free(data->temp.tmp);
		data->temp.i++;
	}
	cf_code(data);
}

void	process_and_cleanup(t_map *data)
{
	close(data->temp.fd);
	manage_data(data->temp.str, data);
	free(data->temp.str);
	free(data->temp.buffer);
}

void	get_map_data(const char *filename, t_map *data)
{
	if (!open_file_and_allocate_memory(filename, data))
		return ;
	read_file_and_join_strings(data);
	process_and_cleanup(data);
}
