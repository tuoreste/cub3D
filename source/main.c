/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:20:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/01/22 13:48:01 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_exit(t_data *data, char *str)
{
	mlx_close_window(data->mlx);
	mlx_strerror(mlx_errno);
	write(2, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int	initialization(t_data *data, t_img *img)
{
	int	i;

	i = 0;
	data->win_mlx = mlx_image_to_window(data->mlx, img->img, SCREEN_W, SCREEN_H);
	img->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	data->rays = ft_calloc(sizeof(t_ray), 1);
	data->player = ft_calloc(sizeof(t_player), 1);
}

int	pass_parsing(t_data *data, t_map *map, char **argv)
{
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;

	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf,
				BUFFER_SIZE)) > 0)
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
void	manage_directions(char *s, t_map *data)
{
	char	**t;

	t = ft_split(s, ' ');
	if (t[0][0] == 'N')
		data->north = ft_strdup(t[1]);
	else if (t[0][0] == 'S')
		data->south = ft_strdup(t[1]);
	else if (t[0][0] == 'W')
		data->west = ft_strdup(t[1]);
	else if (t[0][0] == 'E')
		data->east = ft_strdup(t[1]);
}
void	manage_sfc(char *s, t_map *data)
{
	char	**t;

	t = ft_split(s, ' ');
	if (t[0][0] == 'F')
		data->f = ft_strdup(t[1]);
	else if (t[0][0] == 'S')
		data->s = ft_strdup(t[1]);
	else if (t[0][0] == 'C')
		data->c = ft_strdup(t[1]);
}
t_map	*manage_data(char *s)
{
	int		i;
	t_map	*data;
	char	**t;
	char	**t1;
	char	*map;

	data = (t_map *)malloc(sizeof(t_map));
	map = "";
	i = 0;
	t = ft_split(s, '\n');
	while (t[i])
	{
		char *s = ft_strtrim(t[i], "0123456789 \tNSWE");
		if (!ft_strnstr(t[i], "NO", 2) || !ft_strnstr(t[i], "SO", 2)
			|| !ft_strnstr(t[i], "WE", 2) || !ft_strnstr(t[i], "EA", 2))
			manage_directions(t[i], data);
		else if (!ft_strnstr(t[i], "S", 1) || !ft_strnstr(t[i], "C", 1)
			|| !ft_strnstr(t[i], "F", 1))
			manage_sfc(t[i], data);
		else if (!ft_strnstr(t[i], "S", 1))
		{
			t1 = ft_split(t[i], ' ');
			data->h = ft_atoi(t1[1]);
			data->w = ft_atoi(t1[2]);
		}
		else if (ft_strlen(s) == 0)
		{
			printf("%s\n", t[i]); //<--------------<------------
			map = ft_strjoin(map, t[i]);
			map = ft_strjoin(map, "\n");
		}
		i++;
			printf("%s\n", map);
	}
	data->map = ft_split(map, '\n');
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
	while ((line = get_next_line(fd)) != NULL)
	{
		str = ft_strjoin(str, line);
		free(line);
	}
	close(fd);
	data = manage_data(str);
	return (data);
}
int	checkmap(char **s)
{
	int		i;
	char	*c;

	i = 1;
	if (ft_strtrim(s[0], " 1 \t") != NULL)
		return (0);
	while (s[i])
	{
		c = ft_strtrim(s[i], " \t");
		if (ft_strtrim(s[i], "0123456789 \tNSWE") && c[0] != '1'
			&& c[ft_strlen(c) - 1] != '1')
			return (0);
		i++;
	}
	if (ft_strtrim(s[i], " 1 \t"))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	// t_data	*data;
	// t_img	*img;
	// data = ft_calloc(sizeof(t_data), 1);
	if (argc != 2 || ft_strnstr(argv[1], ".cub", 4))
		printf("error");
	// 	return (error_exit(data->mlx, "Add one arg (map with ext '.cub')"));
	// data->mlx = mlx_init(SCREEN_W, SCREEN_H, "CUBE3D", 100);
	// if (!data->mlx)
	// 	return (error_exit(data->mlx, "MLX Failed to init"));
	map = get_map_data(argv[1]);
	// if (!checkmap(map->map))
	// 	return (1);
	// initialization(&data, &img);
	// pass_parsing(data, &map, argv);
	// free(data);
}
