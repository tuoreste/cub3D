/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:13:08 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/18 15:11:16 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	fix_angles(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_floor_ceiling(t_map *data, int ray, int t_pix, int b_pix)
{
	int		i;
	// int		c;
	char	**t;
	char	**t2;

	i = b_pix;
	t = ft_split(data->f, ',');
	t2 = ft_split(data->c, ',');
	while (i < S_H)
		put_pixel_accordingly(data, ray, i++, ft_pixel(ft_atoi(t[0]),
				ft_atoi(t[1]), ft_atoi(t[2]), 255));
	i = 0;
	while (i < t_pix)
		put_pixel_accordingly(data, ray, i++, ft_pixel(ft_atoi(t2[0]),
				ft_atoi(t2[1]), ft_atoi(t2[2]), 255));
}

int	get_color(t_mlx *mlx, int f)
{
	mlx->ray->r_angle = fix_angles(mlx->ray->r_angle);
	if (f == 0)
	{
		if (mlx->ray->r_angle > M_PI / 2 && mlx->ray->r_angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF);
		else
			return (0xB5B5B5FF);
	}
	else
	{
		if (mlx->ray->r_angle > 0 && mlx->ray->r_angle < M_PI)
			return (0xF5F5F5FF);
		else
			return (0xF5F5F5FF);
	}
}

void	render_wall(t_map *data, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	data->mlx.ray->dist *= cos(fix_angles(data->mlx.ray->r_angle
			- data->mlx.player->angle));
	wall_h = (TILE_SIZE / data->mlx.ray->dist) * ((S_W / 2)
		/ tan(data->mlx.player->fov / 2));
	b_pix = (S_H / 2) + (wall_h / 2);
	t_pix = (S_H / 2) - (wall_h / 2);
	if (b_pix > S_H)
		b_pix = S_H;
	if (t_pix < 0)
		t_pix = 0;
	data->mlx.ray->index = ray;
	draw_wall(data, t_pix, b_pix, wall_h);
	draw_floor_ceiling(data, ray, t_pix, b_pix);
}
