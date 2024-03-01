/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:54:16 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/01 14:06:55 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(void *m)
{
	t_mlx	*mlx;

	mlx = m;
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, W_W, W_H);
	//hooking(mlx, 0, 0);
	ray_casting(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
}

void	begin(t_data *data)
{
	t_mlx	mlx;

	mlx.data = data;
	mlx.player = ft_calloc(1, sizeof(t_player));
	mlx.ray = ft_calloc(1, sizeof(t_ray));
	mlx.mlx = mlx_init(W_W, W_H, "Cub3D", 0);
	mlx.player->player_x = mlx.data->pos_x * TILE + TILE / 2;
	mlx.player->player_y = mlx.data->pos_y * TILE + TILE / 2;
	mlx.player->fov_radius = (FOV * M_PI) / 180;
	mlx.player->angle = M_PI;
	//------>init_player(mlx);------>eliminated
	mlx_loop_hook(mlx.mlx, &game, &mlx);
	//mlx_key_hook(mlx.mlx, &mlx_key, &mlx);
	mlx_loop(mlx.mlx);
	// exit_game(&mlx);
}

t_data	*args_init()
{
	t_data	*data = ft_calloc(1, sizeof(t_data));
	data->map_2d = calloc(10, sizeof(char *));
	data->map_2d[0] = ft_strdup("1111111111111111111111111");
	data->map_2d[1] = ft_strdup("1000000000000000000100001");
	data->map_2d[2] = ft_strdup("1001000000000P00000000001");
	data->map_2d[3] = ft_strdup("1001000000000000001000001");
	data->map_2d[4] = ft_strdup("1001000000000000001000001");
	data->map_2d[5] = ft_strdup("1001000000100000001000001");
	data->map_2d[6] = ft_strdup("1001000000000000001000001");
	data->map_2d[7] = ft_strdup("1001000000001000001000001");
	data->map_2d[8] = ft_strdup("1111111111111111111111111");
	data->map_2d[9] = NULL;
	data->pos_y = 3;
	data->pos_x = 14;
	data->map_wid = 25;
	data->map_hei = 9;
	return (data);
}

int	within_the_arc(float angle, char axi)
{
	if (axi == 'x')
		return (angle > 0 && angle < M_PI);
	else if (axi == 'y')
		return (angle > (M_PI / 2) && angle < (3 * M_PI) / 2);
	return (0);
}

int	is_intersecting(float angle, float *intersect, float *step, int x_axi)
{
	if (x_axi)
	{
		if (angle > 0 && angle < M_PI)
		{
			*intersect += TILE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*intersect += TILE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	did_ray_hit_wall(float x, float y, t_mlx *mlx)
{
	int	x_point_map;
	int	y_point_map;

	if (x < 0 || y < 0)
		return (0);
	x_point_map = floor (x / TILE);
	y_point_map = floor (y / TILE);
	if ((y_point_map >= mlx->data->map_hei) || (x_point_map >= mlx->data->map_wid))
		return (0);
	if (mlx->data->map_2d[y_point_map] && x_point_map <= (int)ft_strlen(mlx->data->map_2d[y_point_map]))
		if (mlx->data->map_2d[y_point_map][x_point_map] == '1')
			return (0);
	return (1);
}

float	horizo_axi_intersect(t_mlx *mlx, float angle)
{
	float	climb_x;
	float	climb_y;
	float	forward_x;
	float	forward_y;
	int		pixel;

	forward_x = TILE;
	forward_y = TILE / tan(angle);
	climb_y = floor (mlx->player->player_y / TILE) * TILE;
	pixel = is_intersecting(angle, &climb_y, &forward_y, 1);
	climb_x = mlx->player->player_x + (climb_y - mlx->player->player_y) / tan(angle);
	if ((within_the_arc(angle, 'y') && forward_x > 0) || (!within_the_arc(angle, 'y') && forward_x < 0))
		forward_x *= -1;
	while (did_ray_hit_wall(climb_x, climb_y - pixel, mlx))
	{
		climb_x += forward_x;
		climb_y += forward_y;
	}
	return (sqrt(pow(climb_x - mlx->player->player_x, 2) + pow(climb_y - mlx->player->player_y, 2)));
}

float	vert_axi_intersect(t_mlx *mlx, float angle)
{
	float	climb_x;
	float	climb_y;
	float	forward_x;
	float	forward_y;
	int		pixel;

	forward_x = TILE;
	forward_y = TILE / tan(angle);
	climb_x = floor (mlx->player->player_x / TILE) * TILE;
	pixel = is_intersecting(angle, &climb_x, &forward_x, 0);
	climb_y = mlx->player->player_y + (climb_x - mlx->player->player_x) / tan(angle);
	if ((within_the_arc(angle, 'x') && forward_y > 0) || (!within_the_arc(angle, 'x') && forward_y < 0))
		forward_y *= -1;
	while (did_ray_hit_wall(climb_x - pixel, climb_y, mlx))
	{
		climb_x += forward_x;
		climb_y += forward_y;
	}
	return (sqrt(pow(climb_x - mlx->player->player_x, 2) + pow(climb_y - mlx->player->player_y, 2)));
}

void	ray_casting(t_mlx *mlx)
{
	double	h_axi_intersect;
	double	v_axi_intersect;
	int		ray;

	ray = 0;
	mlx->ray->ray_angle = mlx->player->angle - (mlx->player->fov_radius / 2);
	while (ray < W_W)
	{
		mlx->ray->wall_flg = 0;
		h_axi_intersect = horizo_axi_intersect(mlx, normalize_angle(mlx->ray->ray_angle));
		v_axi_intersect = vert_axi_intersect(mlx, normalize_angle(mlx->ray->ray_angle));
		if (v_axi_intersect <= h_axi_intersect)
			mlx->ray->dist_to_wall = v_axi_intersect;
		else
		{
			mlx->ray->dist_to_wall = h_axi_intersect;
			mlx->ray->wall_flg = 1;
		}
		rendering(mlx, ray);
		ray++;
		mlx->ray->ray_angle += (mlx->player->fov_radius / W_W);
	}
}

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= W_W)
}

int	main()
{
	t_data	*data;

	data = args_init();
	begin(data);
	return (0);
}
