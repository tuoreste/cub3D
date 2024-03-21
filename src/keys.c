/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:59:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/22 00:01:50 by otuyishi         ###   ########.fr       */
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
