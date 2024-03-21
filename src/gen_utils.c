/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:18:19 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/21 23:53:34 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_exit(t_map *data, char *sms, int i)
{
	free(data->c);
	free(data->f);
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
	free_split(data->map);
	if (i == 1)
	{
		free(data->texture->ea);
		free(data->texture->no);
		free(data->texture->we);
		free(data->texture->so);
		free(data->texture);
		mlx_delete_image(data->mlx.mlx_p, data->mlx.img);
		mlx_terminate(data->mlx.mlx_p);
		free(data->mlx.player);
		free(data->mlx.ray);
	}
	printf("%s\n", sms);
	return ;
}

void	put_pixel_accordingly(t_map *data, int x, int y, unsigned int color)
{
	if (x < 0)
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0)
		return ;
	else if (y >= S_H)
		return ;
	mlx_put_pixel(data->mlx.img, x, y, color);
}

int	check_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
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
