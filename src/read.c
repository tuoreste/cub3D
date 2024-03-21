/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:42:21 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/21 17:42:40 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file_and_allocate_memory(const char *filename, t_map *data)
{
	data->temp.fd = open(filename, O_RDONLY);
	if (data->temp.fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	data->temp.str = ft_strdup("");
	if (!data->temp.str)
	{
		close(data->temp.fd);
		perror("Memory allocation error");
		return (0);
	}
	data->temp.buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!data->temp.buffer)
	{
		perror("Memory allocation error");
		free(data->temp.str);
		close(data->temp.fd);
		return (0);
	}
	return (1);
}

void	read_file_and_join_strings(t_map *data)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = read(data->temp.fd, data->temp.buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		data->temp.buffer[bytes_read] = '\0';
		tmp = ft_strjoin(data->temp.str, data->temp.buffer);
		free(data->temp.str);
		if (!tmp)
		{
			perror("Memory allocation error");
			close(data->temp.fd);
			return (free(data->temp.str), free(data->temp.buffer));
		}
		data->temp.str = tmp;
		bytes_read = read(data->temp.fd, data->temp.buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		perror("Error reading file");
		close(data->temp.fd);
		return (free(data->temp.str), free(data->temp.buffer));
	}
}
