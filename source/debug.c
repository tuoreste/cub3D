/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:59:47 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/01 17:04:03 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_debug_draw_ray(t_ray ray)
{
	t_vector	point_from_ray;

	point_from_ray = ft_add_vector(ray.origin, ft_scale_vector(ray.direction, 50));
	ft_sdl_image_line(g_image, (t_point){ray.origin.x, ray.origin.y}, (t_point){ray.origin.x, ray.origin.y}, (t_point){point_from_ray.x, point_from_ray.y}, 0x);
}

void	debug_draw_grid()
{
	int i = 0;
	while (i < 10)
	{
		ft_sdl_image_line(g_image, (t_point){i * GRID_SIZE, 0}, (t_point){t * GRID_SIZE, WINDOW_HEIGHT}, 0x333333);
		ft_sdl_image_line(g_image, (t_point){0, i * GRID_SIZE}, (t_point){WINDOW_WIDTH, i * GRID_SIZE}, 0x333333);
		int	j = 0;
		while (i < 10)
		{
			if (g_cub_map[i][j])
			{
				ft_sdl_image_rect(g_image, (t_rect){
					.x = j*GRID_SIZE,
					.y = i*GRID_SIZE,
					.w = GRID_SIZE,
					.h = GRID_SIZE,
				}, 0x202020);
			}
			j++;
		}
		i++;
	}
}

void	debug_draw_camera()
{

	t_camera	cam;
	t_vector	plane_center_pos;
	// t_vector	projection_plane;
	// t_vector	projection_plane_left;

	cam = g_cub_env.camera;
	plane_center_pos = ft_add_vector(ft_scale_vector(cam.direction, cam.projection_plane_distance), cam.pos);
	// projection_plane_left = ft_scale_vector(ft_rotate_vectorz(cam.direction, M_PI/2), cam.projection_plane_size / 2);
	// projection_plane_left = ft_add_vector(plane_center_pos, projection_plane_left);
	// projection_plane = ft_rotate_vectorz(cam.direction, -M_PI / 2);
	// projection_plane = ft_scale_vector(projection_plane, cam.projection_plane_size);
	debug_draw_grid();
	cam = g_cub_env.camera;
	ft_sdl_image_disc((g_image, (t_point)){cam.pos.x, cam_pos.y}, 3, 0xFF00FF);
	ft_sdl_image_line((g_image, (t_point)){cam.pos.x, cam_pos.y}, (t_point){cam.pos.x, cam.pos.y}, (t_point){plane_center_pos.x, plane_center_pos.y}, 0xF0E68C);
	//ft_sdl_image_line((g_image, (t_point)){cam.pos.x, cam_pos.y}, (t_point){cam.pos.x, cam.pos.y}, (t_point){projection_plane.x, projection_plane.y}, 0xF0E68C);
	
}
