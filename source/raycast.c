/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:44:18 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/06 14:09:48 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_game *game)
{
	// Clear the window
	mlx_clear_window(game->mlx, game->win);
	// Draw the maze and player
	draw_maze(game);
	draw_player(game);
	// Present the rendered scene
	//mlx_put_image_to_window(game->mlx, game->win, game->image->img, 0, 0);
}

void	cast_rays(t_game *game)
{
	double	ray_angle;
	int		hit_wall;
	double	dist_to_wall;
	double	wall_height;
	int		strip;

	double ray_x, ray_y;
	double delta_x, delta_y;
	double side_dist_x, side_dist_y;
	double step_x, step_y;
	strip = 0;
	while (strip < WINDOW_WIDTH)
	{
		// Calculate ray angle
		ray_angle = game->player.direction - (FOV_ANGLE / 2) + (strip
				* FOV_ANGLE / WINDOW_WIDTH);
		// Initialize ray variables
		ray_x = game->player.x;
		ray_y = game->player.y;
		delta_x = cos(ray_angle);
		delta_y = sin(ray_angle);
		hit_wall = 0;
		// Ray casting loop
		while (!hit_wall)
		{
			// Calculate side distances
			side_dist_x = sqrt(1 + (delta_y * delta_y) / (delta_x * delta_x));
			side_dist_y = sqrt(1 + (delta_x * delta_x) / (delta_y * delta_y));
			// Calculate step direction
			if (delta_x < 0)
			{
				step_x = -1;
				side_dist_x = (ray_x - floor(ray_x)) * side_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (ceil(ray_x) - ray_x) * side_dist_x;
			}
			if (delta_y < 0)
			{
				step_y = -1;
				side_dist_y = (ray_y - floor(ray_y)) * side_dist_y;
			}
			else
			{
				step_y = 1;
				side_dist_y = (ceil(ray_y) - ray_y) * side_dist_y;
			}
			// Perform DDA algorithm
			while (!hit_wall)
			{
				// Choose the smallest side distance
				if (side_dist_x < side_dist_y)
				{
					side_dist_x += delta_x;
					ray_x += step_x;
				}
				else
				{
					side_dist_y += delta_y;
					ray_y += step_y;
				}
				// Check for wall hit
				if (game->map[(int)floor(ray_y)][(int)floor(ray_x)] == '1')
				{
					hit_wall = 1;
					// Calculate distance to wall
					if (side_dist_x < side_dist_y)
						dist_to_wall = side_dist_x;
					else
						dist_to_wall = side_dist_y;
					// Calculate wall height based on distance
					wall_height = (TILE_SIZE / dist_to_wall)
						* game->player.dist_to_projection_plane;
					// Draw the wall strip
					draw_wall_strip(game, strip, wall_height);
					break ;
				}
			}
		}
		strip++;
	}
}
