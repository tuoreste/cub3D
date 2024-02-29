/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:54:16 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/29 14:05:34 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(void *m)
{
	t_mlx	*mlx;

	mlx = m;
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, W_W, W_H);
	//hook(mlx, 0, 0);
	//cast_rays(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
}

void	init_player(t_mlx mlx)
{
	mlx.player->player_x = mlx.data->pos_x * TILE + TILE / 2;
	mlx.player->player_y = mlx.data->pos_y * TILE + TILE / 2;
	mlx.player->fov_radius = (FOV * M_PI) / 180;
	mlx.player->angle = M_PI;
}

void	begin(t_data *data)
{
	t_mlx	mlx;

	mlx.data = data;
	mlx.player = ft_calloc(1, sizeof(t_player));
	mlx.ray = ft_calloc(1, sizeof(t_ray));
	mlx.mlx = mlx_init(W_W, W_H, "Cub3D", 0);
	init_player(mlx);
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

int	main()
{
	t_data	*data;

	data = args_init();
	begin(data);
	return (0);
}
