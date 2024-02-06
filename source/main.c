/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:20:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/06 19:41:32 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void read_scene_file(char *file_path, t_game *game)
{
	int fd;
	char *line;
	size_t len;
	int map_start;
	int line_number;
	char *token;

	line = NULL;
	len = 0;
	map_start = -1;
	line_number = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		line_number++;
		// Remove trailing newline character
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		// Skip empty lines
		if (strlen(line) == 0)
			continue;
		// Skip comments
		if (line[0] == '#')
			continue;
		// Split the line into tokens
		token = strtok(line, " ");
		if (token == NULL)
		{
			fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
			exit(EXIT_FAILURE);
		}
		// Process each token based on its type
		if (strcmp(token, "NO") == 0)
		{
			// Parse North texture path
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.north_texture = (t_texture *)ft_strdup(token);
		}
		else if (strcmp(token, "SO") == 0)
		{
			// Parse South texture path
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.south_texture = (t_texture *)ft_strdup(token);
		}
		else if (strcmp(token, "WE") == 0)
		{
			// Parse West texture path
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.west_texture = (t_texture *)ft_strdup(token);
		}
		else if (strcmp(token, "EA") == 0)
		{
			// Parse East texture path
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.east_texture = (t_texture *)ft_strdup(token);
		}
		else if (strcmp(token, "F") == 0)
		{
			// Parse floor color
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.floor_color.r = atoi(token);
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.floor_color.g = atoi(token);
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.floor_color.b = atoi(token);
		}
		else if (strcmp(token, "C") == 0)
		{
			// Parse ceiling color
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.ceiling_color.r = atoi(token);
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.ceiling_color.g = atoi(token);
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.ceiling_color.b = atoi(token);
		}
		else if (strcmp(token, "1") == 0 || strcmp(token, "0") == 0)
		{
			// Start of the map
			if (map_start == -1)
				map_start = line_number;
			// Store the map line
			strcpy(game->maze.map[line_number - map_start], line);
		}
		else
		{
			fprintf(stderr, "Error: Unknown token at line %d\n", line_number);
			exit(EXIT_FAILURE);
		}
		free(line); // Free memory allocated by get_next_line
	}
	close(fd);
	if (map_start == -1)
	{
		fprintf(stderr, "Error: No map found in scene file\n");
		exit(EXIT_FAILURE);
	}
}

void	update(t_game *game)
{
	if (game->keys.up)
		move_player_forward(game);
	if (game->keys.down)
		move_player_backward(game);
	if (game->keys.left)
		rotate_player_left(game);
	if (game->keys.right)
		rotate_player_right(game);
	// Render the scene
	render(game);
}

void update_wrapper(void *param) {
    update((t_game *)param);
}

// void	render_walls(t_game *game)
// {
// 	int     x;
// 	double  ray_angle;
// 	t_raycast_result    strip;

// 	x = 0;
// 	while (x < game->window_width)
// 	{
// 		ray_angle = game->player.rotation_angle - (game->fov_angle / 2) +
// 					((double)x / game->window_width) * game->fov_angle;
// 		cast_ray(game, ray_angle, &strip);
// 		draw_wall_strip(game, strip, x);
// 		x++;
// 	}
// }

// void	draw_wall_strip(t_game *game, t_raycast_result strip, int column)
// {
// 	int     wall_height;
// 	int     wall_start;
// 	int     wall_end;

// 	wall_height = (int)(game->window_height / strip.distance);
// 	wall_start = (game->window_height / 2) - (wall_height / 2);
// 	wall_end = (game->window_height / 2) + (wall_height / 2);
// 	// Draw the wall strip from wall_start to wall_end at column
// 	// Use strip.texture_id to determine the texture to apply
// }

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		printf("Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	read_scene_file(argv[1], &game);
	setup_game(&game);
	// mlx_loop_hook(game.mlx, update, &game);
	mlx_loop_hook(game.mlx, update_wrapper, &game);

	// mlx_hook(game.win, 2, 1L << 0, key_pressed, &game);
	// mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	// mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
