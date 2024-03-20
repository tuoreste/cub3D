/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:01:11 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/20 21:00:40 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	manage_data(char *s, t_map *data)
{
	int		i;
	char	*tmp_map;

	i = 0;
	data->temp.map = ft_strdup(""); // Initialize map string
	data->temp.t = ft_split(s, '\n');
	while (data->temp.t[i])
	{
		data->temp.tmp = ft_strtrim(data->temp.t[i], " \t012NSWE");
		if (ft_strnstr(data->temp.t[i], "NO", 2) || ft_strnstr(data->temp.t[i],
				"SO", 2) || ft_strnstr(data->temp.t[i], "WE", 2)
			|| ft_strnstr(data->temp.t[i], "EA", 2))
			manage_directions(data->temp.t[i], data);
		else if (ft_strnstr(data->temp.t[i], "S", 1)
			|| ft_strnstr(data->temp.t[i], "C", 1)
			|| ft_strnstr(data->temp.t[i], "F", 1))
			manage_sfc(data->temp.t[i], data);
		else if (ft_strlen(data->temp.tmp) == 0)
		{
			tmp_map = ft_strjoin(data->temp.map, data->temp.t[i]);
			if (!tmp_map)
			{
				free_split(data->temp.t);
				free(data->temp.map);
				return ;
			}
			free(data->temp.map);
			data->temp.map = tmp_map;
			data->temp.map = ft_strjoin(data->temp.map, "\n");
			free(tmp_map);
		}
		free(data->temp.tmp);
		i++;
	}
	free_split(data->temp.t);
	data->map = ft_split(data->temp.map, '\n');
	free(data->temp.map);
	getmapcord(data);
	if (!data->c)
		data->c = ft_strdup("163,208,230");
	if (!data->f)
		data->f = ft_strdup("163,208,230");
}

// void	manage_data(char *s, t_map *data)
// {
// 	int	i;

// 	i = 0;
// 	data->temp.map = "";
// 	data->temp.t = ft_split(s, '\n');
// 	while (data->temp.t[i])
// 	{
// 		data->temp.tmp = ft_strtrim(data->temp.t[i], " \t012NSWE");
// 		if (ft_strnstr(data->temp.t[i], "NO", 2) || ft_strnstr(data->temp.t[i],
// 				"SO", 2) || ft_strnstr(data->temp.t[i], "WE", 2)
// 			|| ft_strnstr(data->temp.t[i], "EA", 2))
// 			manage_directions(data->temp.t[i], data);
// 		else if (ft_strnstr(data->temp.t[i], "S", 1)
// 			|| ft_strnstr(data->temp.t[i], "C", 1)
// 			|| ft_strnstr(data->temp.t[i], "F", 1))
// 			manage_sfc(data->temp.t[i], data);
// 		else if (ft_strnstr(data->temp.t[i], "S", 1))
// 		{
// 			data->temp.t1 = ft_split(data->temp.t[i], ' ');
// 			data->h = ft_atoi(data->temp.t1[1]);
// 			data->w = ft_atoi(data->temp.t1[2]);
// 			free_split(data->temp.t1);
// 		}
// 		else if (ft_strlen(data->temp.tmp) == 0)
// 		{
// 			char *tmp_map = ft_strjoin(data->temp.map, data->temp.t[i]);
// 			if (!tmp_map)
// 			{
// 				// Handle memory allocation error
// 				// Free previously allocated resources before returning
// 				free_split(data->temp.t);
// 				free(data->temp.map);
// 				// Additional cleanup if needed
// 				return ;
// 			}
// 			free(data->temp.map);  // Free previous allocation
// 			data->temp.map = tmp_map;  // Assign new value
// 			data->temp.map = ft_strjoin(data->temp.map, "\n");
// 		}
// 		free(data->temp.tmp);
// 		i++;
// 	}
// 	free_split(data->temp.t);
// 	data->map = ft_split(data->temp.map, '\n');
// 	free(data->temp.map);
// 	getmapcord(data);
// 	if (!data->c)
// 		data->c = ft_strdup("163,208,230");
// 	if (!data->f)
// 		data->f = ft_strdup("163,208,230");
// }

// void get_map_data(char *s, t_map *data)
// {
// 	data->temp.fd = open(s, O_RDONLY);
// 	if (data->temp.fd == -1) {
// 		perror("Error opening file");
// 		return ;
// 	}
// 	data->temp.str = ft_strdup("");
// 	char buffer[BUFFER_SIZE];
// 	if (!data->temp.str) {
// 		close(data->temp.fd);
// 		perror("Memory allocation error");
// 		return ;
// 	}
// 	int bytes_read;
// 	while ((bytes_read = read(data->temp.fd, buffer, BUFFER_SIZE)) > 0) {
// 		buffer[bytes_read] = '\0';
// 		char *tmp = ft_strjoin(data->temp.str, buffer);
// 		free(data->temp.str);
// 		data->temp.str = tmp;
// 	}
// 	close(data->temp.fd);
// 	if (bytes_read == -1) {
// 		perror("Error reading file");
// 		free(data->temp.str);
// 		return ;
// 	}
// 	manage_data(data->temp.str, data);
// 	free(data->temp.str);
// 	system("leaks cub3d");
// }

// void get_map_data(char *s, t_map *data)
// {
// 	data->temp.fd = open(s, O_RDONLY);
// 	if (data->temp.fd == -1) {
// 		perror("Error opening file");
// 		return ;
// 	}

// 	data->temp.str = ft_strdup("");
// 	if (!data->temp.str) {
// 		close(data->temp.fd);
// 		perror("Memory allocation error");
// 		return ;
// 	}
// 	//buffer = malloc(sizeof(char) * (BUFFER + 1))
// 	char buffer[BUFFER_SIZE];
// 	ssize_t bytes_read;
// 	while ((bytes_read = read(data->temp.fd, buffer, BUFFER_SIZE)) > 0) {
// 		buffer[bytes_read] = '\0';
// 		char *tmp = ft_strjoin(data->temp.str, buffer);
// 		free(data->temp.str);
// 		if (!tmp) {
// 			perror("Memory allocation error");
// 			close(data->temp.fd);
// 			free(data->temp.str);
// 			return ;
// 		}
// 		data->temp.str = tmp;
// 	}
// 	if (bytes_read == -1) {
// 		perror("Error reading file");
// 		free(data->temp.str);
// 		close(data->temp.fd);
// 		return ;
// 	}
// 	close(data->temp.fd);
// 	manage_data(data->temp.str, data);
// 	free(data->temp.str);
// 	system("leaks cub3d");
// }

void	get_map_data(char *s, t_map *data)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*tmp;

	data->temp.fd = open(s, O_RDONLY);
	if (data->temp.fd == -1)
	{
		perror("Error opening file");
		return ;
	}
	data->temp.str = ft_strdup("");
	if (!data->temp.str)
	{
		close(data->temp.fd);
		perror("Memory allocation error");
		return ;
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		perror("Memory allocation error");
		free(data->temp.str);
		close(data->temp.fd);
		return ;
	}
	while ((bytes_read = read(data->temp.fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(data->temp.str, buffer);
		free(data->temp.str);
		if (!tmp)
		{
			perror("Memory allocation error");
			close(data->temp.fd);
			free(data->temp.str);
			free(buffer);
			return ;
		}
		data->temp.str = tmp;
	}
	if (bytes_read == -1)
	{
		perror("Error reading file");
		free(data->temp.str);
		free(buffer);
		close(data->temp.fd);
		return ;
	}
	close(data->temp.fd);
	manage_data(data->temp.str, data);
	free(data->temp.str);
	free(buffer);
}
