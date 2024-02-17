/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:26:18 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/17 13:27:55 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initiate_rays(t_maps *map, t_ray *ray, int x)
{
	map->ray.cam_x = x * 2 / (double)WINDOW_WIDTH - 1;
	ray->dir_ray[X] = map->vect[DIR].x + (map->vect[CAM].x * map->ray.cam_x);
	ray->dir_ray[Y] = map->vect[DIR].y + (map->vect[CAM].y * map->ray.cam_x);
	ray->tile[X] = (int)map->vect[POS].x;
	ray->tile[Y] = (int)map->vect[POS].y;
}

void	compute_ray_steps(t_maps *map, t_ray *ray)
{
	if (ray->dir_ray[X] < 0)
	{
		ray->step[X] = -1;
		ray->dist_to_nxt_contour[X]
			= (map->vect[POS].x - (double)ray->tile[X]) * ray->portion_of_rem_tile[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->dist_to_nxt_contour[X]
			= (ray->tile[X] + 1.0 - map->vect[POS].x) * ray->portion_of_rem_tile[X];
	}
	if (ray->dir_ray[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->dist_to_nxt_contour[Y]
			= (map->vect[POS].y - (double)ray->tile[Y]) * ray->portion_of_rem_tile[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->dist_to_nxt_contour[Y]
			= (ray->tile[Y] + 1.0 - map->vect[POS].y) * ray->portion_of_rem_tile[Y];
	}
}

t_render	feed_info_to_render(t_maps *map, t_ray *ray)
{
	t_game		*game;
	double		x_wall;
	t_render	render;

	render.h_line = (int)WINDOW_HEIGHT / ray->perp_wall_dist;
	render.ratio = (int)TILE / render.h_line;
	render.draw_strt = (WINDOW_HEIGHT / 2) - (render.h_line / 2);
	render.draw_end = (WINDOW_HEIGHT / 2) + (render.h_line / 2);
	if (render.draw_strt < 0)
		render.draw_strt = 0;
	if (render.draw_end >= WINDOW_HEIGHT)
		render.draw_end = WINDOW_HEIGHT - 1;
	if (ray->s == 0)
		x_wall = map->vect[POS].y + ray->perp_wall_dist * ray->dir_ray[Y];
	else
		x_wall = map->vect[POS].x + ray->perp_wall_dist * ray->dir_ray[X];
	x_wall -= floor(x_wall);
	game->x_texture = (int) (x_wall * (double)TILE);
	if ((ray->s == 0 && ray->dir_ray[X] > 0)
		|| (ray->s == 1 && ray->dir_ray[Y] < 0))
		game->x_texture = TILE - game->x_texture - 1;
	render.pix_texture[X] = game->x_texture;
	return (render);
}
