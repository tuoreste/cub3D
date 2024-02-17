/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:17:36 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/15 18:23:17 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	direction(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{//forward
		game->map->vect[POS].x += MOV_SPEED * game->map->vect[DIR].x;
		game->map->vect[POS].y += MOV_SPEED * game->map->vect[DIR].y;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{//backwards
		game->map->vect[POS].x -= MOV_SPEED * game->map->vect[DIR].x;
		game->map->vect[POS].y -= MOV_SPEED * game->map->vect[DIR].y;
	}
}

void	camera(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{//Right
		game->map->vect[POS].x += MOV_SPEED * game->map->vect[CAM].x;
		game->map->vect[POS].y += MOV_SPEED * game->map->vect[CAM].y;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{//Left
		game->map->vect[POS].x -= MOV_SPEED * game->map->vect[CAM].x;
		game->map->vect[POS].y -= MOV_SPEED * game->map->vect[CAM].y;
	}
}

void	rotation(t_game *game)
{
	double initial_dir_x;
	double r;
	double l;

	initial_dir_x = game->map->vect[DIR].x;
	r = -(ROT_SP);
	l = ROT_SP;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{//Rightward(-)
		game->map->vect[DIR].x
			= initial_dir_x * cos(r) - game->map->vect[DIR].y * sin(r);
		game->map->vect[DIR].y
			= initial_dir_x * sin(r) + game->map->vect[DIR].y * cos(r);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{//Leftward(+)
		game->map->vect[DIR].x
			= initial_dir_x * cos(l) - game->map->vect[DIR].y * sin(l);
		game->map->vect[DIR].y
			= initial_dir_x * sin(l) + game->map->vect[DIR].y * cos(l);
	}
}

void	move(void *param)
{
	t_game	*game;
	static int32_t	*update_w;
	static int32_t	*update_h;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_all(); //make sure to free everything allocated before exit
		mlx_close_window(game->mlx);
	}
	direction(game);
	camera(game);
	rotation(game);
	mlx_get_monitor_size(0, update_w, update_h);
	ray_casting(game);
}
