/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:02:26 by aguediri          #+#    #+#             */
/*   Updated: 2024/03/24 06:17:26 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_sec_arg(char *argv)
{
	if (ft_strnstr(argv, "maps/map_a.cub", 14) || ft_strnstr(argv,
			"maps/map_b.cub", 14) || ft_strnstr(argv, "maps/map_c.cub", 14))
		return (1);
	return (0);
}

void	game_loop(void *ml)
{
	t_map	*data;

	data = ml;
	mlx_delete_image(data->mlx.mlx_p, data->mlx.img);
	data->mlx.img = mlx_new_image(data->mlx.mlx_p, S_W, S_H);
	if (!data->mlx.img)
		return ;
	hook(data, 0, 0);
	raycast(data);
	mlx_image_to_window(data->mlx.mlx_p, data->mlx.img, 0, 0);
}

void	start_game(t_map *data)
{
	data->mlx.mlx_p = mlx_init(S_W, S_H, "Cub3D", 0);
	if (!get_texture_data(data))
		return ;
	data->mlx.player->player_x = data->p_x * TILE_SIZE + TILE_SIZE / 2;
	data->mlx.player->player_y = data->p_y * TILE_SIZE + TILE_SIZE / 2;
	data->mlx.player->fov = (FOV * M_PI) / 180;
	data->mlx.player->angle = M_PI;
	mlx_loop_hook(data->mlx.mlx_p, &game_loop, data);
	mlx_key_hook(data->mlx.mlx_p, &mlx_key, data);
	mlx_loop(data->mlx.mlx_p);
	mlx_close_window(data->mlx.mlx_p);
}

int	main(int argc, char **argv)
{
	t_map	data;

	if (argc != 2)
		return (printf("Wrong Number of args"), 1);
	if (!check_sec_arg(argv[1]))
		return (printf("Map name error,\nchoose btn:\n1.maps/map_a.cub, \
			\n2.maps/map_b.cub,\n3.maps/map_c.cub\n"), 1);
	get_map_data(argv[1], &data);
	if (data.map[0] && checkmap(&data))
	{
		data.mlx.player = calloc(1, sizeof(t_player));
		if (!data.mlx.player)
			return (ft_exit(&data, "Memo Alloc Error", 0), 1);
		data.mlx.ray = calloc(1, sizeof(t_ray));
		if (!data.mlx.ray)
			return (ft_exit(&data, "Memo Alloc Error", 0), 1);
		start_game(&data);
		ft_exit(&data, "Game over!!", 1);
	}
	else
		return (ft_exit(&data, "Invalid data", 0), 1);
	return (0);
}
