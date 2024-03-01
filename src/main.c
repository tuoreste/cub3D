/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:54:16 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/01 19:35:01 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exiting(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->data->map_2d[i])
		free(mlx->data->map_2d[i++]);
	free(mlx->data->map_2d);
	free(mlx->data);
	free(mlx->player);
	free(mlx->ray);
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx_close_window(mlx->mlx);
	mlx_terminate(mlx->mlx);
	printf("\n\n\n\n\n----->CLOSEDDDD<-----\n\n\n\n\n");
	exit(0);
}

void	game(void *m)
{
	t_mlx	*mlx;

	mlx = m;
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, W_W, W_H);
	hooking(mlx, 0, 0);
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
	mlx_key_hook(mlx.mlx, &mlx_key, &mlx);
	mlx_loop(mlx.mlx);
	exiting(&mlx);
}

t_data	*args_init(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->map_2d = calloc(10, sizeof(char *));
	data->map_2d[0] = ft_strdup("1111111111111111111111111");
	data->map_2d[1] = ft_strdup("1000000000000000000000001");
	data->map_2d[2] = ft_strdup("1000000000000000000000001");
	data->map_2d[3] = ft_strdup("1000000000000000000000001");
	data->map_2d[4] = ft_strdup("1000000000000000000000001");
	data->map_2d[5] = ft_strdup("1000000000000000000000001");
	data->map_2d[6] = ft_strdup("1000000000000000000000001");
	data->map_2d[7] = ft_strdup("1000000000000000000000001");
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
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (axi == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
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
	x_point_map = floor(x / TILE);
	y_point_map = floor(y / TILE);
	if ((y_point_map >= mlx->data->map_hei)
		|| (x_point_map >= mlx->data->map_wid))
		return (0);
	if (mlx->data->map_2d[y_point_map]
		&& x_point_map <= (int)ft_strlen(mlx->data->map_2d[y_point_map]))
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
	climb_y = floor(mlx->player->player_y / TILE) * TILE;
	pixel = is_intersecting(angle, &climb_y, &forward_y, 1);
	climb_x = mlx->player->player_x + (climb_y - mlx->player->player_y)
		/ tan(angle);
	if ((within_the_arc(angle, 'y') && forward_x > 0) || (!within_the_arc(angle,
				'y') && forward_x < 0))
		forward_x *= -1;
	while (did_ray_hit_wall(climb_x, climb_y - pixel, mlx))
	{
		climb_x += forward_x;
		climb_y += forward_y;
	}
	return (sqrt(pow(climb_x - mlx->player->player_x, 2) + pow(climb_y
				- mlx->player->player_y, 2)));
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
	climb_x = floor(mlx->player->player_x / TILE) * TILE;
	pixel = is_intersecting(angle, &climb_x, &forward_x, 0);
	climb_y = mlx->player->player_y + (climb_x - mlx->player->player_x)
		* tan(angle);
	if ((within_the_arc(angle, 'x') && forward_y < 0) || (!within_the_arc(angle,
				'x') && forward_y > 0))
		forward_y *= -1;
	while (did_ray_hit_wall(climb_x - pixel, climb_y, mlx))
	{
		climb_x += forward_x;
		climb_y += forward_y;
	}
	return (sqrt(pow(climb_x - mlx->player->player_x, 2) + pow(climb_y
				- mlx->player->player_y, 2)));
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
		h_axi_intersect = horizo_axi_intersect(mlx,
				adjust_angle(mlx->ray->ray_angle));
		v_axi_intersect = vert_axi_intersect(mlx,
				adjust_angle(mlx->ray->ray_angle));
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
		return ;
	if (y < 0)
		return ;
	else if (y >= W_H)
		return ;
	mlx_put_pixel(mlx->img, x, y, color);
}

float	adjust_angle(float angle)
{
	if (angle < 0)
		angle += (M_PI * 2);
	if (angle > (M_PI * 2))
		angle -= (M_PI * 2);
	return (angle);
}

void	paint_ceil_floor(t_mlx *mlx, int ray, int ceil_pixel, int floor_pixel)
{
	int	i;
	int	c;

	i = floor_pixel;
	while (i < W_H)
		pixel_put(mlx, ray, i++, 0xB99470FF);
	i = 0;
	while (i < ceil_pixel)
		pixel_put(mlx, ray, i++, 0xFFFFFFFF);
}

int	fetch_colors(t_mlx *mlx, int boool)
{
	mlx->ray->ray_angle = adjust_angle(mlx->ray->ray_angle);
	if (boool == 0)
	{
		if (mlx->ray->ray_angle > M_PI / 2 && mlx->ray->ray_angle < 3 * (M_PI
				/ 2))
			return (0xBEBEBEFF);
		else
			return (0xBEBEBEFF);
	}
	else
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < M_PI)
			return (0xFFADD8E6);
		else
			return (0xFFADD8E6);
	}
}

void	paint_wall(t_mlx *mlx, int ray, int ceil_pixel, int floor_pixel)
{
	int	color;

	color = fetch_colors(mlx, mlx->ray->wall_flg);
	while (ceil_pixel < floor_pixel)
		pixel_put(mlx, ray, ceil_pixel++, color);
}

void	rendering(t_mlx *mlx, int ray)
{
	double	wall_hei;
	double	ceil_pixel;
	double	floor_pixel;

	mlx->ray->dist_to_wall *= cos(adjust_angle(mlx->ray->ray_angle
				- mlx->player->angle));
	wall_hei = (TILE / mlx->ray->dist_to_wall) * ((W_W / 2)
			/ tan(mlx->player->fov_radius / 2));
	floor_pixel = (W_H / 2) + (wall_hei / 2);
	ceil_pixel = (W_H / 2) - (wall_hei / 2);
	if (floor_pixel > W_H)
		floor_pixel = W_H;
	if (ceil_pixel < 0)
		ceil_pixel = 0;
	paint_wall(mlx, ray, ceil_pixel, floor_pixel);
	paint_ceil_floor(mlx, ray, ceil_pixel, floor_pixel);
}

void	releasing_button(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		mlx->player->left_right = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		mlx->player->left_right = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		mlx->player->up_down = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		mlx->player->up_down = 0;
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_RELEASE))
		mlx->player->rotate = 0;
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_RELEASE))
		mlx->player->rotate = 0;
}

void	mlx_key(mlx_key_data_t keydata, void *m)
{
	t_mlx	*mlx;

	mlx = m;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		exiting(mlx);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		mlx->player->left_right = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		mlx->player->left_right = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		mlx->player->up_down = -1;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS))
		mlx->player->up_down = 1;
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS))
		mlx->player->rotate = -1;
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS))
		mlx->player->rotate = 1;
	releasing_button(keydata, mlx);
}

void	rotate_player(t_mlx *mlx, int i)
{
	if (i == 1)
	{
		mlx->player->angle += ROT_SP;
		if (mlx->player->angle > 2 * M_PI)
			mlx->player->angle -= 2 * M_PI;
	}
	else
	{
		mlx->player->angle -= ROT_SP;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * M_PI;
	}
}

void	player_movements(t_mlx *mlx, double x_mov, double y_mov)
{
	int	grid_x;
	int	grid_y;
	int	refre_x;
	int	refre_y;

	refre_x = roundf(mlx->player->player_x + x_mov);
	refre_y = roundf(mlx->player->player_y + y_mov);
	grid_x = refre_x / TILE;
	grid_y = refre_y / TILE;
	if (mlx->data->map_2d[grid_y][grid_x] != '1'
		&& (mlx->data->map_2d[grid_y][mlx->player->player_x / TILE] != '1'
			&& mlx->data->map_2d[mlx->player->player_y / TILE][grid_x] != '1'))
	{
		mlx->player->player_x = refre_x;
		mlx->player->player_y = refre_y;
	}
}

void	hooking(t_mlx *mlx, double x_mov, double y_mov)
{
	if (mlx->player->rotate == 1)
		rotate_player(mlx, 1);
	if (mlx->player->rotate == -1)
		rotate_player(mlx, 0);
	if (mlx->player->left_right == 1)
	{
		x_mov = -sin(mlx->player->angle) * PLY_SP;
		y_mov = cos(mlx->player->angle) * PLY_SP;
	}
	if (mlx->player->left_right == -1)
	{
		x_mov = sin(mlx->player->angle) * PLY_SP;
		y_mov = -cos(mlx->player->angle) * PLY_SP;
	}
	if (mlx->player->up_down == 1)
	{
		x_mov = cos(mlx->player->angle) * PLY_SP;
		y_mov = sin(mlx->player->angle) * PLY_SP;
	}
	if (mlx->player->up_down == -1)
	{
		x_mov = -cos(mlx->player->angle) * PLY_SP;
		y_mov = -sin(mlx->player->angle) * PLY_SP;
	}
	player_movements(mlx, x_mov, y_mov);
}

int	main(void)
{
	t_data	*data;

	data = args_init();
	begin(data);
	return (0);
}
