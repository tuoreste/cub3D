/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:11:52 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/15 18:41:18 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initkeys(mlx_key_data_t keydata, t_map *data)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		data->mlx.player->l_r = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		data->mlx.player->l_r = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		data->mlx.player->u_d = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		data->mlx.player->u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		data->mlx.player->rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		data->mlx.player->rot = 0;
}

void	mlx_key(mlx_key_data_t keydata, void *ml)
{
	t_map	*data;

	data = ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		ft_exit(data, "Exiting...");
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		data->mlx.player->l_r = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		data->mlx.player->l_r = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		data->mlx.player->u_d = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->mlx.player->u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		data->mlx.player->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		data->mlx.player->rot = 1;
	ft_initkeys(keydata, data);
}

// void	move_player(t_map *data, double move_x, double move_y)
// {
// 	int	map_grid_y;
// 	int	map_grid_x;
// 	int	new_x;
// 	int	new_y;

// 	new_x = round(data->mlx.player->player_x + move_x);
// 	new_y = round(data->mlx.player->player_y + move_y);
// 	map_grid_x = (new_x / TILE_SIZE);
// 	map_grid_y = (new_y / TILE_SIZE);
// 	if (data->map[map_grid_y][map_grid_x] != '1'
// 		&& (data->map[map_grid_y][data->mlx.player->player_x / TILE_SIZE] != '1'
// 			&& data->map[data->mlx.player->player_y
// 			/ TILE_SIZE][map_grid_x] != '1'))
// 	{
// 		data->mlx.player->player_x = new_x;
// 		data->mlx.player->player_y = new_y;
// 	}
// }

int	is_valid_move(t_map *data, double refresh_x, double refresh_y)
{
	int	map_grid_y;
	int	map_grid_x;

	map_grid_y = floor(refresh_y / TILE_SIZE);
	map_grid_x = floor(refresh_x / TILE_SIZE);
	return (map_grid_y >= 0 && map_grid_y < data->h_map && map_grid_x >= 0
		&& map_grid_x < data->w_map
		&& data->map[map_grid_y][map_grid_x] != '1');
}

void	move_player(t_map *data, double move_x, double move_y)
{
	double	refresh_x;
	double	refresh_y;

	refresh_x = data->mlx.player->player_x + move_x;
	refresh_y = data->mlx.player->player_y + move_y;
	if (is_valid_move(data, refresh_x, refresh_y))
	{
		data->mlx.player->player_x = refresh_x;
		data->mlx.player->player_y = refresh_y;
	}
}

void	rotation(t_map *data)
{
	if (data->mlx.player->rot == 1)
	{
		data->mlx.player->angle += ROTATION_SPEED;
		if (data->mlx.player->angle > 2 * M_PI)
			data->mlx.player->angle -= 2 * M_PI;
	}
	if (data->mlx.player->rot == -1)
	{
		data->mlx.player->angle -= ROTATION_SPEED;
		if (data->mlx.player->angle < 0)
			data->mlx.player->angle += 2 * M_PI;
	}
}

void	hook(t_map *data, double move_x, double move_y)
{
	rotation(data);
	if (data->mlx.player->l_r == 1)
	{
		move_x = -sin(data->mlx.player->angle) * PLAYER_SPEED;
		move_y = cos(data->mlx.player->angle) * PLAYER_SPEED;
	}
	if (data->mlx.player->l_r == -1)
	{
		move_x = sin(data->mlx.player->angle) * PLAYER_SPEED;
		move_y = -cos(data->mlx.player->angle) * PLAYER_SPEED;
	}
	if (data->mlx.player->u_d == 1)
	{
		move_x = cos(data->mlx.player->angle) * PLAYER_SPEED;
		move_y = sin(data->mlx.player->angle) * PLAYER_SPEED;
	}
	if (data->mlx.player->u_d == -1)
	{
		move_x = -cos(data->mlx.player->angle) * PLAYER_SPEED;
		move_y = -sin(data->mlx.player->angle) * PLAYER_SPEED;
	}
	move_player(data, move_x, move_y);
}
