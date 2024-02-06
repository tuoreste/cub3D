/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:20:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/06 14:36:32 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_scene_file(char *file_path, t_game *game)
{
	int		fd;
	char	*line;
	size_t	len;
	ssize_t	read;
	int		map_start;
	int		line_number;
	char	*token;

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
	while ((read = getline(&line, &len, fd)) != -1)
	{
		line_number++;
		// Remove trailing newline character
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		// Skip empty lines
		if (strlen(line) == 0)
			continue ;
		// Skip comments
		if (line[0] == '#')
			continue ;
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
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.north_texture.path = strdup(token);
		}
		else if (strcmp(token, "SO") == 0)
		{
			// Parse South texture path
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.south_texture.path = strdup(token);
		}
		else if (strcmp(token, "WE") == 0)
		{
			// Parse West texture path
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.west_texture.path = strdup(token);
		}
		else if (strcmp(token, "EA") == 0)
		{
			// Parse East texture path
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.east_texture.path = strdup(token);
		}
		else if (strcmp(token, "F") == 0)
		{
			// Parse floor color
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.floor_color.r = atoi(token);
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.floor_color.g = atoi(token);
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
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
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.ceiling_color.r = atoi(token);
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			game->settings.ceiling_color.g = atoi(token);
			token = strtok(NULL, ",");
			if (token == NULL)
			{
				fprintf(stderr, "Error: Invalid format at line %d\n",
					line_number);
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
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, 2, 1L << 0, key_pressed, &game);
	mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
