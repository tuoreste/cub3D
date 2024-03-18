/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:16:43 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/18 15:11:20 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_data(t_map *data)
{
	data->texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!data->texture)
		return (0);
	data->texture->ea = mlx_load_png(data->east);
	if (!data->texture->ea)
		return (0);
	data->texture->so = mlx_load_png(data->south);
	if (!data->texture->so)
		return (0);
	data->texture->no = mlx_load_png(data->north);
	if (!data->texture->no)
		return (0);
	data->texture->we = mlx_load_png(data->west);
	if (!data->texture->we)
		return (0);
	return (1);
}

mlx_texture_t	*get_texture(t_map *data, int flag)
{
	data->mlx.ray->r_angle = fix_angles(data->mlx.ray->r_angle);
	if (flag == 0)
	{
		if (data->mlx.ray->r_angle > M_PI / 2 && data->mlx.ray->r_angle < 3
			* (M_PI / 2))
			return (data->texture->ea);
		else
			return (data->texture->so);
	}
	else
	{
		if (data->mlx.ray->r_angle > 0 && data->mlx.ray->r_angle < M_PI)
			return (data->texture->we);
		else
			return (data->texture->no);
	}
}

double	get_x_o(mlx_texture_t *texture, t_map *data)
{
	double	x_o;
	double	dist_to_wall;
	double	wall_hit_x;
	double	wall_hit_y;

	dist_to_wall = data->mlx.ray->dist;
	if (data->mlx.ray->f == 1)
	{
		wall_hit_x = data->mlx.player->player_x + (dist_to_wall
			* cos(data->mlx.ray->r_angle));
		x_o = fmod(wall_hit_x, TILE_SIZE) / TILE_SIZE * texture->width;
	}
	else
	{
		wall_hit_y = data->mlx.player->player_y + (dist_to_wall
			* sin(data->mlx.ray->r_angle));
		x_o = fmod(wall_hit_y, TILE_SIZE) / TILE_SIZE * texture->width;
	}
	return (x_o);
}

unsigned int reverse_bytes(int c)
{
    return ((c & 0x000000FF) << 24) |
           ((c & 0x0000FF00) << 8) |
           ((c & 0x00FF0000) >> 8) |
           ((c & 0xFF000000) >> 24);
}

void	draw_wall(t_map *data, int t_pix, int b_pix, double wall_h)
{
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;
	double			x_o;
	double			y_o;
	int				texture_index;

	texture = get_texture(data, data->mlx.ray->f);
	if (texture == NULL)
		return ;
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_o = get_x_o(texture, data);
	y_o = (t_pix + (wall_h / 2) - (S_H / 2)) * factor;
	if (y_o < 0)
		y_o = 0.1;
	while (t_pix < b_pix)
	{
		y_o = fmax(0.1, y_o);
		texture_index = (int)y_o * texture->width + (int)x_o;
		if (texture_index < (int)(texture->height * texture->width))
			put_pixel_accordingly(data, data->mlx.ray->index, t_pix,
				reverse_bytes(arr[texture_index]));
		y_o += factor;
		t_pix++;
	}
}
