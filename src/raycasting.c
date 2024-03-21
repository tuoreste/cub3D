/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:05:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/21 16:59:18 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_intersection(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	check_wall_hit(float x, float y, t_map *dt)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor(x / TILE_SIZE);
	y_m = floor(y / TILE_SIZE);
	if ((y_m >= dt->h_map || x_m >= dt->w_map))
		return (0);
	if (dt->map[y_m] && x_m <= (int)strlen(dt->map[y_m]))
	{
		if (dt->map[y_m][x_m] == '1')
			return (0);
		else
			return (1);
	}
	return (1);
}

float	get_horizontal_int(t_map *data, float angl)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(data->mlx.player->player_y / TILE_SIZE) * TILE_SIZE;
	pixel = check_intersection(angl, &h_y, &y_step, 1);
	h_x = data->mlx.player->player_x + (h_y - data->mlx.player->player_y)
		/ tan(angl);
	if ((check_circle(angl, 'y') && x_step > 0) || (!check_circle(angl, 'y')
			&& x_step < 0))
		x_step *= -1;
	while (check_wall_hit(h_x, h_y - pixel, data))
	{
		h_x += x_step;
		h_y += y_step;
	}
	data->mlx.ray->horiz_x = h_x;
	data->mlx.ray->horiz_y = h_y;
	return (sqrt(pow(h_x - data->mlx.player->player_x, 2) + pow(h_y
				- data->mlx.player->player_y, 2)) + 0.00001);
}

float	get_vertical_int(t_map *data, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(data->mlx.player->player_x / TILE_SIZE) * TILE_SIZE;
	pixel = check_intersection(angl, &v_x, &x_step, 0);
	v_y = data->mlx.player->player_y + (v_x - data->mlx.player->player_x)
		* tan(angl);
	if ((check_circle(angl, 'x') && y_step < 0) || (!check_circle(angl, 'x')
			&& y_step > 0))
		y_step *= -1;
	while (check_wall_hit(v_x - pixel, v_y, data))
	{
		v_x += x_step;
		v_y += y_step;
	}
	data->mlx.ray->horiz_x = v_x;
	data->mlx.ray->horiz_y = v_y;
	return (sqrt(pow(v_x - data->mlx.player->player_x, 2) + pow(v_y
				- data->mlx.player->player_y, 2)));
}

void	raycast(t_map *data)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	data->mlx.ray->r_angle = data->mlx.player->angle - (data->mlx.player->fov
			/ 2);
	while (ray <= S_W)
	{
		data->mlx.ray->f = 0;
		h_inter = get_horizontal_int(data, fix_angles(data->mlx.ray->r_angle));
		v_inter = get_vertical_int(data, fix_angles(data->mlx.ray->r_angle));
		if (v_inter < h_inter)
			data->mlx.ray->dist = v_inter;
		else
		{
			data->mlx.ray->dist = h_inter;
			data->mlx.ray->f = 1;
		}
		render_wall(data, ray);
		ray++;
		data->mlx.ray->r_angle += (data->mlx.player->fov / S_W);
	}
}
