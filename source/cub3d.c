/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:55:21 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/18 13:57:19 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*launch_game(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->scrn_h = WINDOW_HEIGHT;
	game->scrn_h = WINDOW_WIDTH;
	game->map->etage = 0;
	// printf("hiiiiiiiii");
	game->map->plafo = 0;
	return (game);
}

void	maze(void *param)
{
	int 		x;
	t_render	render;
	t_game		*game;
	t_ray		*ray; // need to be allocated

	game = (t_game *)param;
	select_color(game);
	x = -1;
	while (++x < game->scrn_w)
	{
		initiate_rays(game->map, ray, x);
		reciprocate_dir_vec(game->map, ray, x);
		compute_ray_steps(game->map, ray);
		draw_line_dda(game->map, ray, game);
		render = feed_info_to_render(game->map, ray);
		game->y_texture = (int)render.pos_texture & (TILE - 1);
		game->color = pull_color_texture(game->walls[render.dir_wall]
			, render.pix_texture[X], game->y_texture);
		while (render.draw_strt < render.draw_end)
		{
			mlx_put_pixel(game->img, x, render.draw_strt, game->color);
			render.pos_texture += render.ratio;
			render.draw_strt++;
		}
	}
}

int	build_game(t_game *game)
{
	game = launch_game(game);
	if (!upload_texture(game))
		return (error_gen("Error: texture not loading\n")); //texture not loading
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "42 CUB3D", 100);
	if (game->mlx == NULL)
		return(error_gen("Error: MLX initiation failed\n"));
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (game->img == NULL)
		return(error_gen("Error: Image creation failed\n"));
	if (mlx_image_to_window(game->mlx, game->img, 0, 0))
		return(error_gen("Error: Image to window failed\n"));
	if (!mlx_loop_hook(game->mlx, move, game)
		|| !mlx_loop_hook(game->mlx, maze, game))
		return(error_gen("Error: move/maze problem\n"));
	mlx_loop(game->mlx);
	return (0);
}
