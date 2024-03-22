/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:59:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/22 12:59:35 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_key_release(t_map *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		data->mlx.player->l_r = 0;
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_W)
		data->mlx.player->u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		data->mlx.player->rot = 0;
}

void	handle_key_press(t_map *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_A)
		data->mlx.player->l_r = -1;
	else if (keydata.key == MLX_KEY_D)
		data->mlx.player->l_r = 1;
	else if (keydata.key == MLX_KEY_S)
		data->mlx.player->u_d = -1;
	else if (keydata.key == MLX_KEY_W)
		data->mlx.player->u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT)
		data->mlx.player->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT)
		data->mlx.player->rot = 1;
}

void	mlx_key(mlx_key_data_t keydata, void *ml)
{
	t_map *data = ml;
	if (keydata.action == MLX_PRESS)
		handle_key_press(data, keydata);
	else if (keydata.action == MLX_RELEASE)
		handle_key_release(data, keydata);
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		printf("Exiting...");
		mlx_close_window(data->mlx.mlx_p);
		return ;
	}
}

void	update_player_direction(t_map *data)
{
	if (data->mlx.player->rot == 1)
	{
		data->mlx.player->angle += ROTATION_SPEED;
		if (data->mlx.player->angle > 2 * M_PI)
			data->mlx.player->angle -= 2 * M_PI;
	}
	else if (data->mlx.player->rot == -1)
	{
		data->mlx.player->angle -= ROTATION_SPEED;
		if (data->mlx.player->angle < 0)
			data->mlx.player->angle += 2 * M_PI;
	}
}

void	calc_ride(t_map *data, double *x_ride, double *y_ride)
{
	double	angle;

	angle = data->mlx.player->angle;
	if (data->mlx.player->l_r != 0)
	{
		*x_ride = sin(angle) * (data->mlx.player->l_r * PLAYER_SPEED);
		*y_ride = cos(angle) * (data->mlx.player->l_r * PLAYER_SPEED);
	}
	else if (data->mlx.player->u_d != 0)
	{
		*x_ride = cos(angle) * (data->mlx.player->u_d * PLAYER_SPEED);
		*y_ride = sin(angle) * (data->mlx.player->u_d * PLAYER_SPEED);
	}
	else
	{
		*x_ride = 0;
		*y_ride = 0;
	}
}

void	hook(t_map *data, double x_ride, double	y_ride)
{
	update_player_direction(data);
	calc_ride(data, &x_ride, &y_ride);
	move_player(data, x_ride, y_ride);
}

