/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:51:20 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/18 16:39:43 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	upload_texture(t_game *game)
{
	int	i;

	i = -1;
	if (game->map->north)
	{
		game->map->texture[0] = ft_strdup(game->map->north);
		game->map->texture[1] = ft_strdup(game->map->south);
		game->map->texture[2] = ft_strdup(game->map->east);
		game->map->texture[3] = ft_strdup(game->map->west);
	}
	while (++i < 4)
	{
		game->walls[i] = mlx_load_png(game->map->texture[i]);
		if (game->walls[i] == NULL)
			return (error_gen("Error: Texture upload failed\n"));
	}
	return (0);
}

int	pull_color_texture(mlx_texture_t *texture, int x_texture, int y_texture)
{
	int	color;

	if (x_texture < 0)
		x_texture = 0;
	else if (x_texture > TILE)
		x_texture = TILE - 1;
	if (y_texture < 0)
		y_texture = 0;
	else if (y_texture > TILE)
		y_texture = TILE - 1;
	color = *(texture->pixels + y_texture * TILE + x_texture);
	return (color);
}

int	color_rgba(int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

void	select_color(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->scrn_h / 2)
	{
		x = -1;
		while (++x < game->scrn_w)
			mlx_put_pixel(game->img, x, y, game->map->etage);
	}
	y = game->scrn_h / 2;
	game->map->etage = color_rgba(game->map->floor[0], game->map->floor[1],
			game->map->floor[2]);
	game->map->plafo = color_rgba(game->map->ceil[0], game->map->ceil[1],
			game->map->ceil[2]);
	while (y < game->scrn_h)
	{
		x = -1;
		while (++x < game->scrn_w)
			mlx_put_pixel(game->img, x, y, game->map->plafo);
		y++;
	}
	game->map->etage = color_rgba(game->map->floor[0], game->map->floor[1],
			game->map->floor[2]);
	game->map->plafo = color_rgba(game->map->ceil[0], game->map->ceil[1],
			game->map->ceil[2]);
}
