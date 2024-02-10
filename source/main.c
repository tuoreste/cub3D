/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:53:15 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/10 20:03:47 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int world_map[]=
// {
// 	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,
// 	1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,
// 	1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
// 	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
// };

// int		*world_map[] = {(int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1,
// 			1, 1, 1, 1, 1, 1, 1, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0,
// 			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0,
// 			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 			(int[]){1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1,
// 			0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
// 			0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
// 			0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 1, 0,
// 			0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0,
// 			0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
// 			(int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 			0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 			0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 					(int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 						0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0,
// 						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1,
// 						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 						0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 1, 1, 1,
// 						1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 						1}, (int[]){1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
// 						0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 1, 0, 0, 0, 0, 1,
// 						0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 						(int[]){1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
// 						0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 1, 0, 1, 1, 1, 1, 1,
// 						1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 						(int[]){1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
// 						0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 1, 1, 1, 1, 1, 1, 1,
// 						1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 						(int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
// 						1, 1, 1, 1, 1, 1, 1, 1}};

int		*world_map[] = {(int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			(int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 1}, (int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			(int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					(int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
						(int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
						(int[]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 1}, (int[]){1, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
						(int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 1, 1, 1, 1, 1}};

// void	rotate_image(t_game *game)
// {
// 	game->image->img_width = WINDOW_WIDTH;
// 	game->image->img_height = WINDOW_HEIGHT;
// 	game->image->center_x = game->image->img_width / 2;
// 	game->image->center_y = game->image->img_height / 2;
// 	game->image->rotated_data = (unsigned int *)malloc(game->image->img_width
// 			* game->image->img_height * sizeof(unsigned int));
// 	game->image->radians = game->image->angle * (PI / 180.0);
// 	game->image->y = 0;
// 	while (game->image->y < game->image->img_height)
// 	{
// 		game->image->x = 0;
// 		while (game->image->x < game->image->img_width)
// 		{
// 			game->image->relative_x = game->image->x - game->image->center_x;
// 			game->image->relative_y = game->image->y - game->image->center_y;
// 			game->image->new_x = game->image->center_x
// 				+ (game->image->relative_x * cos(game->image->radians)
// 					- game->image->relative_y * sin(game->image->radians));
// 			game->image->new_y = game->image->center_y
// 				+ (game->image->relative_y * sin(game->image->radians)
// 					+ game->image->relative_y * cos(game->image->radians));
// 			if (game->image->new_x >= 0 && game->image->new_x
// 				< game->image->img_width && game->image->new_y >= 0
// 				&& game->image->new_y < game->image->img_height)
// 				game->image->rotated_data[game->image->new_y * game->image->img_width
//  					+ game->image->new_x] = *((unsigned int *)game->image->img + game->image->y
//  						* game->image->img_width + game->image->x);
// 			game->image->x++;
// 		}
// 		game->image->y++;
// 	}
// 	free(game->image);
// 	game->image->img = (void *)game->image->rotated_data;
// }

void	buttons(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	// game->image->player_orient = 0.0f;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->player->img->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->player->img->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->player->img->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->player->img->instances[0].x += 5;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	// 	game->image->player_orient -= 5.0f;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	// 	game->image->player_orient += 5.0f;
}

// void	draw_player(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	game->player = (t_player *)ft_calloc(sizeof(t_player), 1);
// 	game->player->img = mlx_new_image(game->mlx, 10, 10);
// 	// rotate_image(game);
// 	mlx_image_to_window(game->mlx, game->player->img, WINDOW_WIDTH / 2,
// 		WINDOW_HEIGHT / 2);
// 	game->player->p_y = 0;
// 	while (game->player->p_y < 5)
// 	{
// 		game->player->p_x = 0;
// 		while (game->player->p_x < 5)
// 		{
// 			mlx_put_pixel(game->player->img, game->player->p_x,
// 				game->player->p_y, 0xFF0000FF);
// 			game->player->p_x++;
// 		}
// 		game->player->p_y++;
// 	}
// }
#include <math.h>

void mlx_draw_line(int x0, int y0, int x1, int y1, void *img)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1)
    {
        mlx_put_pixel(img, x0, y0, 0xFF0000FF);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_player(mlx_key_data_t keydata ,void *param)
{
    t_game  *game;

    game = (t_game *)param;
    game->player = (t_player *)ft_calloc(sizeof(t_player), 1);
    game->player->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

    int radius = 50; // Radius of the circle
    int centerX = WINDOW_WIDTH / 2; // Center x-coordinate
    int centerY = WINDOW_HEIGHT / 2; // Center y-coordinate
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;

    // Draw circle
    while (x >= y)
    {
        mlx_put_pixel(game->player->img, centerX + x, centerY + y, 0xFF0000FF);
        mlx_put_pixel(game->player->img, centerX - x, centerY + y, 0xFF0000FF);
        mlx_put_pixel(game->player->img, centerX + x, centerY - y, 0xFF0000FF);
        mlx_put_pixel(game->player->img, centerX - x, centerY - y, 0xFF0000FF);
        mlx_put_pixel(game->player->img, centerX + y, centerY + x, 0xFF0000FF);
        mlx_put_pixel(game->player->img, centerX - y, centerY + x, 0xFF0000FF);
        mlx_put_pixel(game->player->img, centerX + y, centerY - x, 0xFF0000FF);
        mlx_put_pixel(game->player->img, centerX - y, centerY - x, 0xFF0000FF);

        y++;
        if (radiusError < 0)
        {
            radiusError += 2 * y + 1;
        }
        else
        {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }

	int q = 0;
    // Draw lines every 10 degrees
    for (int angle = 0 + q; angle < 60 + q; angle += 5) {
	if (keydata.key == MLX_KEY_RIGHT)
		q -= 5;
	if (keydata.key == MLX_KEY_LEFT)
		q += 5;
        double angle_rad = angle * M_PI / 180.0; // Convert angle to radians
        int end_x = centerX + (int)(radius * cos(angle_rad));
        int end_y = centerY - (int)(radius * sin(angle_rad));
        mlx_draw_line(centerX, centerY, end_x, end_y, game->player->img);
    }

    mlx_image_to_window(game->mlx, game->player->img, 0, 0);
}

void	draw_map2d(t_game *game)
{
	game->pt.y = 0;
	game->pt.mapx = 0;
	game->pt.mapy = 0;
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "THIS IS CUBE3D", 100);
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	game->pt.y = 0;
	while (game->pt.y < WINDOW_HEIGHT)
	{
		game->pt.x = 0;
		while (game->pt.x < WINDOW_WIDTH)
		{
			game->pt.mapx = game->pt.x * MAP_WIDTH / WINDOW_WIDTH;
			game->pt.mapy = game->pt.y * MAP_HEIGHT / WINDOW_HEIGHT;
			if (world_map[game->pt.mapx][game->pt.mapy] == 1)
				mlx_put_pixel(game->img, game->pt.x, game->pt.y, 0xFFFFFFFF);
			else
				mlx_put_pixel(game->img, game->pt.x, game->pt.y, 0x00000000);
			game->pt.x++;
		}
		game->pt.y++;
	}
}

int	main(void)
{
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	game->img = (t_image *)malloc(sizeof(t_image));
	draw_map2d(game);
	//draw_player(game);
	mlx_key_hook(game->mlx, draw_player, game);
	mlx_loop_hook(game->mlx, buttons, game);
	mlx_loop(game->mlx);
	free(game->player);
	free(game->img);
	free(game);
	return (0);
}
