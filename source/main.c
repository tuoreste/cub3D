/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:20:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/02 13:35:44 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	error_exit(t_data *data, char *str)
// {
// 	mlx_close_window(data->mlx);
// 	mlx_strerror(mlx_errno);
// 	write(2, str, ft_strlen(str));
// 	return (EXIT_FAILURE);
// }

// int	initialization(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	data->win_mlx = mlx_image_to_window(data->mlx, data->px_img, SCREEN_W, SCREEN_H);
// 	data->px_img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
// 	data->rays = ft_calloc(sizeof(t_ray), 1);
// 	data->player = ft_calloc(sizeof(t_player), 1);
// 	data->img = ft_calloc(sizeof(t_img *) * 17, 1);
// 	while (i < 17)
// 	{
// 		data->img[i] = calloc(sizeof(t_img), 1);
// 		i++;
// 	}
// 	data->player->dest_x = 0;
// 	data->player->dest_y = 0;
// 	data->player->pl_x = 0;
// 	data->player->pl_y = 0;
// 	data->player->rotations = 0;
// 	data->player->dir_x = 0;
// 	data->player->dir_y = 0;
// }
// int	pass_parsing(t_data *data, t_map *map, char **argv)
// {
// 	return (1);
// }

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	char		*line;
// 	char		*newline;
// 	int			countread;
// 	int			to_copy;

// 	line = ft_strdup(buf);
// 	while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf,
// 				BUFFER_SIZE)) > 0)
// 	{
// 		buf[countread] = '\0';
// 		line = ft_strjoin(line, buf);
// 	}
// 	if (ft_strlen(line) == 0)
// 		return (free(line), NULL);
// 	newline = ft_strchr(line, '\n');
// 	if (newline != NULL)
// 	{
// 		to_copy = newline - line + 1;
// 		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
// 	}
// 	else
// 	{
// 		to_copy = ft_strlen(line);
// 		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
// 	}
// 	line[to_copy] = '\0';
// 	return (line);
// }
// void	manage_directions(char *s, t_map *data)
// {
// 	char	**t;

// 	t = ft_split(s, ' ');
// 	if (t[0][0] == 'N')
// 		data->north = ft_strdup(t[1]);
// 	else if (t[0][0] == 'S')
// 		data->south = ft_strdup(t[1]);
// 	else if (t[0][0] == 'W')
// 		data->west = ft_strdup(t[1]);
// 	else if (t[0][0] == 'E')
// 		data->east = ft_strdup(t[1]);
// }
// void	manage_sfc(char *s, t_map *data)
// {
// 	char	**t;

// 	t = ft_split(s, ' ');
// 	if (t[0][0] == 'F')
// 		data->f = ft_strdup(t[1]);
// 	else if (t[0][0] == 'S')
// 		data->s = ft_strdup(t[1]);
// 	else if (t[0][0] == 'C')
// 		data->c = ft_strdup(t[1]);
// }
// t_map	*manage_data(char *s)
// {
// 	int		i;
// 	t_map	*data;
// 	char	**t;
// 	char	**t1;
// 	char	*map;

// 	data = (t_map *)malloc(sizeof(t_map));
// 	map = "";
// 	i = 0;
// 	t = ft_split(s, '\n');
// 	while (t[i])
// 	{
// 		char *s = ft_strtrim(t[i], "0123456789 \tNSWE");
// 		if (!ft_strnstr(t[i], "NO", 2) || !ft_strnstr(t[i], "SO", 2)
// 			|| !ft_strnstr(t[i], "WE", 2) || !ft_strnstr(t[i], "EA", 2))
// 			manage_directions(t[i], data);
// 		else if (!ft_strnstr(t[i], "S", 1) || !ft_strnstr(t[i], "C", 1)
// 			|| !ft_strnstr(t[i], "F", 1))
// 			manage_sfc(t[i], data);
// 		else if (!ft_strnstr(t[i], "S", 1))
// 		{
// 			t1 = ft_split(t[i], ' ');
// 			data->h = ft_atoi(t1[1]);
// 			data->w = ft_atoi(t1[2]);
// 		}
// 		else if (ft_strlen(s) == 0)
// 		{
// 			printf("%s\n", t[i]); //<--------------<------------
// 			map = ft_strjoin(map, t[i]);
// 			map = ft_strjoin(map, "\n");
// 		}
// 		i++;
// 			printf("%s\n", map);
// 	}
// 	data->map = ft_split(map, '\n');
// 	return (data);
// }

// t_map	*get_map_data(char *s)
// {
// 	int		fd;
// 	char	*line;
// 	char	*str;
// 	t_map	*data;

// 	fd = open(s, O_RDONLY);
// 	str = "";
// 	data = NULL;
// 	if (!fd)
// 	{
// 		perror("Error opening file");
// 		return (NULL);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		str = ft_strjoin(str, line);
// 		free(line);
// 	}
// 	close(fd);
// 	data = manage_data(str);
// 	return (data);
// }

// int	checkmap(char **s)
// {
// 	int		i;
// 	char	*c;

// 	i = 1;
// 	if (ft_strtrim(s[0], " 1 \t") != NULL)
// 		return (0);
// 	while (s[i])
// 	{
// 		c = ft_strtrim(s[i], " \t");
// 		if (ft_strtrim(s[i], "0123456789 \tNSWE") && c[0] != '1'
// 			&& c[ft_strlen(c) - 1] != '1')
// 			return (0);
// 		i++;
// 	}
// 	if (ft_strtrim(s[i], " 1 \t"))
// 		return (0);
// 	return (1);
// }

// int	main(int argc, char **argv)
// {
// 	t_map	*map;

// 	// t_data	*data;
// 	// t_img	*img;
// 	// data = ft_calloc(sizeof(t_data), 1);
// 	if (argc != 2 || ft_strnstr(argv[1], ".cub", 4))
// 		printf("error");
// 	// 	return (error_exit(data->mlx, "Add one arg (map with ext '.cub')"));
// 	// data->mlx = mlx_init(SCREEN_W, SCREEN_H, "CUBE3D", 100);
// 	// if (!data->mlx)
// 	// 	return (error_exit(data->mlx, "MLX Failed to init"));
// 	map = get_map_data(argv[1]);
// 	// if (!checkmap(map->map))
// 	// 	return (1);
// 	// initialization(&data, &img);
// 	// pass_parsing(data, &map, argv);
// 	// free(data);
// }

int g_cub_map[MAP_W][MAP_H] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

t_point	get_pos_on_grid(t_vector pos)
{
	t_point	result;

	result.x = pos.x / GRID_SIZE;
	result.y = pos.y /GRID_SIZE;
	return (result);
}

int	intersect_with_x(t_dda *dda)
{
	int	gridX, gridY;

	gridX = dda->nextX - 1 + dda->sign.x;
	gridY = dda->pos_on_grid.y;
	if (gridX < 0 || gridX >= MAP_W || gridY < 0 || gridY >= MAP_H)
		return (0);
	if (g_cub_map[gridY][gridX])
	{
		dda->intersection.is_intersection = 1;
		dda->intersection.grid_pos = (t_point){gridX, gridY};
		dda->intersection.grid_value = g_cub_map[gridY][gridX];
		return (1);
	}
	return (0);
}

int	intersect_with_y(t_dda *dda)
{
	int	gridX, gridY;

	gridX = dda->pos_on_grid.x;
	gridY = dda->nextY - 1 + dda.sign.y;
	if (gridX < 0 || gridX >= MAP_W || gridY < 0 || gridY >= MAP_H)
		return (0);
	return (g_cub_map([gridY][gridX]));
}

t_intersect	intersect_ray(t_ray ray)
{
	int	iter;
	t_dda	dda;
	t_dda	dda;

	ft_bzero(&dda, sizeof(t_dda));
	dda.intersection.does_intersect = 0;
	iter = 0;
	dda.current_pos = ray.origin;
	dda.sign = (t_point){1, 1};
	if (ray.direction.x < 0)
		dda.sign.x = 0;
	if (ray.direction.y < 0)
		dda.sign.y = 0;
	while (iter < MAX_VIEW_DISTANCE)
	{
		dda.pos_on_grid = get_pos_on_grid(dda.current_pos);
		dda.nextX = dda.pos_on_grid.x + dda.sign.x;
		dda.nextY = dda.pos_on_grid.y + dda.sign.y;
		dda.next_pos_on_grid.x = dda.nextX *GRID_SIZE;
		dda.next_pos_on_grid.y = dda.nextY *GRID_SIZE;
		dda.d.x = (dda.next_pos_on_grid.x - dda.current_pos.x) / ray.direction.x;
		dda.d.y = (dda.next_pos_on_grid.y - dda.current_pos.y) / ray.direction.y;
		if (dda.d.x < dda.d.y)
		{
			dda.intersection.does_intersect = intersect_with_x(dda);
			dda.final_d = dda.d.x;
		}
		else
		{
			dda.intersection.does_intersect = intersect_with_y(dda);
			dda.final_d = dda.d.y;
		}
		dda.final_d += 0.00001; //because of the double precision issue
		dda.current_pos.x += dda.final_d * ray.direction.x;
		dda.current_pos.y += dda.final_d * ray.direction.y;
		dda.intersection.distance += dda.final_d;
		iter++;
		//debug to visualize the intersectiion of the positions
		int	color = 0xFF00FF;
		if (does_intersect)
			color = 0x00FF00;
		f_sdl_image_pixel(g_image, dda.current_pos.x, dda.current_pos.y, color);
		if (does_intersect)
			break ;
		//end debug
	}
}

void	draw_wall(void)
{
	double	distance;
	int		wall_height;
	int		top_y, bottom_y;

	distance = g_cub_env.camera.intersection.distance;
	wall_height = (WINDOW_HEIGHT / distance) * WALL_HEIGHT_SCALE;
	top_y = WINDOW_HEIGHT / 2 - wall_height / 2;
	bottom_y = top_y + wall_height;
	if (top_y < 0)
		top_y = 0;
	if (bottom_y > WINDOW_HEIGHT)
		bottom_y = WINDOW_HEIGHT;
	while (top_y <= bottom_y)
	{
		ft_sdl_image_pixel(g_image, g_cub_env.camera.intersection.screen_x, top_y, 0xFFFFFF);
		top_y++;
	}
}

int	raycast_camera(t_camera camera)
{
	int			current_screen_x;
	t_vector	current_pos_on_plane;
	t_vector	plane_iter;
	t_ray		current_ray;
	t_vector	pos_to_plane_center;

	current_screen_x = 0;
	pos_to_plane_center = ft_scale_vector(camera.direction, camera.projection_plane_distance);
	camera.left_plane_half = ft_rotate_vectorz(camera.direction, M_PI/2);
	camera.left_plane_half = ft_scale_vector(camera.left_plane_half, camera.projection_plane_size / 2);
	current_pos_on_plane = ft_add_vector(pos_to_plane_center, camera.left_plane_half);
	plane_iter = ft_scale_vector(camera.left_plane_half, -(2/WINDOW_WIDTH));
	current_ray.origin = camera.pos;
	while (current_screen_x < WINDOW_WIDTH)
	{
		current_ray.direction = ft_normalise_vector(current_pos_on_plane);
		// here you should use the ray
		g_cub_env.camera.intersection = intersect_ray(current_ray);
		ft_debug_draw_ray(current_ray); //draw ray on the screen & debugging
		current_pos_on_plane = ft_add_vector(current_pos_on_plane, plane_iter);
		current_screen_x++;
	}
	return (1);
}

int	init(void)
{
	g_cub_env.camera.pos = (t_vector){250, 250};
	g_cub_env.camera.direction = ft_normalise_vector((t_vector){1, 1});
	g_cub_env.camera.projection_plane_distance = 50;
	g_cub_env.camera.projection_plane_size = 100;
	return (1);
}

int	raycast_main(void)
{
	raycast_camera(g_cub_env.camera);
	return (0);
}
