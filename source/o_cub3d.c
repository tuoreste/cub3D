/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_cub3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:20:16 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/07 12:21:20 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void setup_game(t_game *game)
// {
// 	// Initialize mlx with window width and height
// 	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "3D Maze", true);
	
// 	// Load textures
// 	game->textures.north_texture = mlx_load_png("textures/tex1.jpeg");
// 	game->textures.south_texture = mlx_load_png("textures/tex1.jpeg");
// 	game->textures.east_texture = mlx_load_png("textures/tex1.jpeg");
// 	game->textures.west_texture = mlx_load_png("textures/tex1.jpeg");
	
// 	// Set up player position and settings
// 	game->player.x = TILE_SIZE * 1.5;
// 	game->player.y = TILE_SIZE * 1.5;
// 	game->player.direction = 0;
// 	game->player.rotation_angle = FOV_ANGLE / 2;
// 	game->player.move_speed = 5;
// 	game->player.rotation_speed = 2 * (M_PI / 180);
// }

// void	draw_rectangle(t_game *game, int x, int y)
// {
// 	mlx_put_string(game->mlx, game->win, x, y);
// }

// void	draw_player(t_game *game)
// {
// 	int		player_x;
// 	int		player_y;
// 	int		i;
// 	double	ray_angle;
// 	double	ray_x;
// 	double	ray_y;

// 	// Draw the player on the minimap
// 	player_x = game->player.x / TILE_SIZE;
// 	player_y = game->player.y / TILE_SIZE;
// 	draw_rectangle(game, player_x * TILE_SIZE, player_y * TILE_SIZE);
// 	// Red player marker
// 	// Draw the player's field of view (rays)
// 	i = 0;
// 	while (i < NUM_RAYS)
// 	{
// 		ray_angle = game->player.rotation_angle - (FOV_ANGLE / 2) + (i
// 				* FOV_ANGLE / NUM_RAYS);
// 		ray_x = game->player.x + cos(ray_angle) * RAY_LENGTH;
// 		ray_y = game->player.y + sin(ray_angle) * RAY_LENGTH;
// 		// Draw the ray
// 		draw_line(game, game->player.x, game->player.y, ray_x, ray_y, 0x00FF00);
// 		// Green ray
// 		i++;
// 	}
// }

// void	draw_maze(t_game *game)
// {
// 	int	y;
// 	int	x;
// 	int	wall_x;
// 	int	wall_y;
// 	int	floor_x;
// 	int	floor_y;
// 	int	ceiling_x;
// 	int	ceiling_y;
// 	int	wall_color;
// 	int	floor_color;
// 	int	ceiling_color;

// 	y = 0;
// 	while (y < MAP_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < MAP_WIDTH)
// 		{
// 			if (game->map[y][x] == '1') // Check if the cell contains a wall
// 			{
// 				// Draw a rectangle representing the wall
// 				wall_color = 0x808080;
// 				// Gray color for walls (you can change it)
// 				wall_x = x * TILE_SIZE;
// 				wall_y = y * TILE_SIZE;
// 				draw_rectangle(game, wall_x, wall_y);
// 			}
// 			else
// 			{
// 				// Draw the floor and ceiling
// 				floor_color = 0x404040;
// 				// Dark gray color for floor (you can change it)
// 				ceiling_color = 0xC0C0C0;
// 				// Light gray color for ceiling (you can change it)
// 				floor_x = x * TILE_SIZE;
// 				floor_y = y * TILE_SIZE;
// 				ceiling_x = x * TILE_SIZE;
// 				ceiling_y = y * TILE_SIZE;
// 				draw_rectangle(game, floor_x, floor_y);
// 				draw_rectangle(game, ceiling_x, ceiling_y);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

