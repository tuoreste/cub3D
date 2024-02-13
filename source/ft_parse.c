/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:02:15 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/12 11:50:54 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	error_return(char *str)
// {
// 	fprintf(stderr, "%s\n", str);
// 	exit (EXIT_FAILURE);
// }

// void	error_format(char *str, int line_n)
// {
// 	fprintf(stderr, "%s %d\n", str, line_n);
// 	exit(EXIT_FAILURE);
// }

// void	ft_check_format(t_game *game, char *c)
// {
// 	game->parse.token = strtok(NULL, c);
// 	if (game->parse.token == NULL)
// 		error_format("Error: Invalid format at line", game->parse.line_number);
// }

// void	read_scene_file(char *file_path, t_game *game)
// {
// 	game->parse.line = NULL;
// 	game->parse.len = 0;
// 	game->parse.map_start = -1;
// 	game->parse.line_number = 0;
// 	game->parse.fd = open(file_path, O_RDONLY);
// 	if (game->parse.fd == -1)
// 	{
// 		fprintf(stderr, "Error: Unable to open file %s\n", file_path);
// 		exit(EXIT_FAILURE);
// 	}
// 	while ((game->parse.line = get_next_line(game->parse.fd)) != NULL)
// 	{
// 		game->parse.line_number++;
// 		if (game->parse.line[ft_strlen(game->parse.line) - 1] == '\n')
// 			game->parse.line[ft_strlen(game->parse.line) - 1] = '\0';
// 		if (ft_strlen(game->parse.line) == 0)
// 			continue ;
// 		if (game->parse.line[0] == '#')
// 			continue ;
// 		game->parse.token = strtok(game->parse.line, " ");
// 		if (game->parse.token == NULL)
// 			error_format("Error: Invalid format at line",
// 				game->parse.line_number);
// 		if (ft_strncmp(game->parse.token, "NO", 2) == 0)
// 		{
// 			ft_check_format(game, " ");
// 			game->settings.no_tex = (t_texture *)ft_strdup(game->parse.token);
// 		}
// 		else if (ft_strncmp(game->parse.token, "SO", 2) == 0)
// 		{
// 			ft_check_format(game, " ");
// 			game->settings.so_tex = (t_texture *)ft_strdup(game->parse.token);
// 		}
// 		else if (ft_strncmp(game->parse.token, "WE", 2) == 0)
// 		{
// 			ft_check_format(game, " ");
// 			game->settings.we_tex = (t_texture *)ft_strdup(game->parse.token);
// 		}
// 		else if (ft_strncmp(game->parse.token, "EA", 2) == 0)
// 		{
// 			ft_check_format(game, " ");
// 			game->settings.ea_tex = (t_texture *)ft_strdup(game->parse.token);
// 		}
// 		else if (ft_strncmp(game->parse.token, "F", 1) == 0)
// 		{
// 			ft_check_format(game, ",");
// 			game->settings.floor_color.r = ft_atoi(game->parse.token);
// 			ft_check_format(game, ",");
// 			game->settings.floor_color.g = ft_atoi(game->parse.token);
// 			ft_check_format(game, ",");
// 			game->settings.floor_color.b = ft_atoi(game->parse.token);
// 		}
// 		else if (ft_strncmp(game->parse.token, "C", 1) == 0)
// 		{
// 			ft_check_format(game, ",");
// 			game->settings.ceiling_color.r = ft_atoi(game->parse.token);
// 			ft_check_format(game, ",");
// 			game->settings.ceiling_color.g = ft_atoi(game->parse.token);
// 			ft_check_format(game, ",");
// 			game->settings.ceiling_color.b = ft_atoi(game->parse.token);
// 		}
// 		else if (ft_strncmp(game->parse.token, "1", 1) == 0
// 			|| ft_strncmp(game->parse.token, "0", 1) == 0)
// 		{
// 			if (game->parse.map_start == -1)
// 				game->parse.map_start = game->parse.line_number;
// 			ft_strlcpy(game->maze.map[game->parse.line_number
// 				- game->parse.map_start], game->parse.line,
// 				ft_strlen(game->parse.line));
// 		}
// 		else
// 			error_format("Error: Invalid format at line",
// 				game->parse.line_number);
// 		free(game->parse.line);
// 	}
// 	close(game->parse.fd);
// 	if (game->parse.map_start == -1)
// 		error_return("Error: No map found in scene file");
// }
