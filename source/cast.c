/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:28:02 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/17 20:32:00 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reciprocate_dir_vec(t_maps *map, t_ray *ray, int x)
{
	if (ray->dir_ray[Y] == 0)
		ray->portion_of_rem_tile[X] = 0;
	else
	{
		if (ray ->dir_ray[X] == 0)
			ray->portion_of_rem_tile[X] = 1;
		else
			ray->portion_of_rem_tile[X] = fabs(1 / ray->dir_ray[X]);
	}
	if (ray->dir_ray[X] == 0)
		ray->portion_of_rem_tile[Y] = 0;
	else
	{
		if (ray->dir_ray[Y] == 0)
			ray->portion_of_rem_tile[Y] = 1;
		else
			ray->portion_of_rem_tile[Y] = fabs(1 / ray->dir_ray[Y]);
	}
}

void	draw_line_dda(t_maps *map, t_ray *ray, t_game *game)
{
	game->hit = 0;

	while (!game->hit)
	{
		if (ray->dist_to_nxt_contour[X] < ray->dist_to_nxt_contour[Y])
		{
			ray->dist_to_nxt_contour[X] += ray->dist_to_nxt_contour[X];
			ray->tile[X] += ray->step[X];
			ray->s = 0;
		}
		else
		{
			ray->dist_to_nxt_contour[Y] += ray->dist_to_nxt_contour[Y];
			ray->tile[Y] += ray->step[Y];
			ray->s = 0;
		}
		if (map->map[ray->tile[X]][ray->tile[Y]] == '1')
			game->hit = 1;
		if (ray->s == 0)
			ray->perp_wall_dist
				= (ray->tile[X] - map->vect[POS].x + (1 - ray->step[X]) / 2.0)
					/ ray->dir_ray[X];
		else
			ray->perp_wall_dist
				= (ray->tile[Y] - map->vect[POS].y + (1 - ray->step[Y]) / 2.0)
					/ ray->dir_ray[Y];
	}
}
