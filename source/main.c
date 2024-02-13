/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:14 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/13 15:50:17 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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


void	ray_rotation(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		game->pa -= ROT;
		if (game->pa < 0)
			game->pa += 2 * PI;
		game->pdx = cos(game->pa) * 5;
		game->pdy = sin(game->pa) * 5;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		game->pa += 0.1;
		if (game->pa > 0)
			game->pa -= 2 * PI;
		game->pdx = cos(game->pa) * 5;
		game->pdy = sin(game->pa) * 5;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->player->img->instances[0].y -= 5;
		game->player->img->instances[0].x += game->pdx;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->player->img->instances[0].y += 5;
		game->player->img->instances[0].x -= game->pdy;
	}
}

// void	draw_line(t_game *game)
// {
// 	int dx = fabs(game->pdx - game->player->img->instances[0].x);
// 	int dy = fabs(game->pdy - game->player->img->instances[0].y);
// 	int sx = game->player->img->instances[0].x < game->pdx ? 1 : -1;
// 	int sy = game->player->img->instances[0].y < game->pdx ? 1 : -1;
// 	int err = dx - dy;
// 	int e2;
// 	while (1)
// 	{
// 		mlx_put_pixel(game->img, game->player->img->instances[0].x,
			// game->player->img->instances[0].y, 0xFF0000FF);
// 		if (game->player->img->instances[0].x == game->pdx
			// && game->player->img->instances[0].y == game->pdy) break ;
// 		e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			game->player->img->instances[0].x += sx;
// 		}
// 		if (e2 < dx) {
// 			err += dx;
// 			game->player->img->instances[0].y += sy;
// 		}
// 	}
// }
int is_collision_with_wall(t_game *game, int x1, int y1, int x2, int y2)
{
    // Iterate through all points between (x1, y1) and (x2, y2)
    for (int x = x1; x != x2; x += (x2 - x1 > 0) ? 1 : -1) {
        for (int y = y1; y != y2; y += (y2 - y1 > 0) ? 1 : -1) {
            // Calculate map coordinates for current point
            int mapx = x * MAP_WIDTH / WINDOW_WIDTH;
            int mapy = y * MAP_HEIGHT / WINDOW_HEIGHT;

            // Check if current point is a wall
            if (world_map[mapx][mapy] == 1) {
				printf("collision detected");
                return 1; // Collision detected
            }
        }
    }
    return 0; // No collision detected
}
void	buttons(void *param)
{
	t_game	*game;

	game = (t_game *)param;
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
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->i += 10;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->i -= 10;
}
// int is_wall_collision(t_game *game, int x, int y)
// {
//     // Calculate map coordinates for current point
//     int mapx = x * MAP_WIDTH / WINDOW_WIDTH;
//     int mapy = y * MAP_HEIGHT / WINDOW_HEIGHT;

//     // Check if the current point is a wall
//     if (world_map[mapx][mapy] == 1) {
//         return 1; // Collision detected
//     }

//     return 0; // No collision detected
// }
void	draw_line(t_game *game, int x1, int y1, int x2, int y2)
{

	int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {

		if (!is_collision_with_wall(game, x1, y1, x2, y2))
        	mlx_put_pixel(game->player->img, x1 , y1 , 0xFF0000FF);
		printf("x1 = %d\n y1 = %d\n", x1,y1);

        // If the endpoint is reached, exit the loop
        if (x1 == x2 && y1 == y2) {
            break;
        }

        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }

}
void draw_lines_10_degrees(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game*)param;
	
    int x1 = game->player->img->instances[0].x;
    int y1 = game->player->img->instances[0].y;
	int x_center = WINDOW_WIDTH / 2; // Calculate the x-coordinate of the center of the screen
    int y_center = WINDOW_HEIGHT / 2;
    int radius = 200; // Or whatever length you want the lines to be
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		game->i+=10;
    for (int angle = 0 + game->i; angle < 90 + game->i; angle += 7) {
        // Calculate endpoint coordinates based on angle and radius
        int x2 = x_center + radius * cos(angle * M_PI / 180);
        int y2 = y_center + radius * sin(angle * M_PI / 180);

        // Check for collision with walls
        // if (!is_collision_with_wall(game, x1, y1, x2, y2)) {
        //     // Draw line between (x1, y1) and (x2, y2)
            draw_line(game, x1, y1, x2, y2);
         }
		
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		game->i-=10;
    for (int angle = 0 + game->i; angle < 90 + game->i; angle += 7) {
        // Calculate endpoint coordinates based on angle and radius
        int x2 = x_center + radius * cos(angle * M_PI / 180);
        int y2 = y_center + radius * sin(angle * M_PI / 180);

        // Check for collision with walls
        // if (!is_collision_with_wall(game, x1, y1, x2, y2)) {
        //     // Draw line between (x1, y1) and (x2, y2)
            draw_line(game, x1, y1, x2, y2);
         }
		
	}
}

void	draw_player(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_image_to_window(game->mlx, game->player->img, 0,0);
	game->player->y = WINDOW_HEIGHT / 2;
	while (game->player->y < (WINDOW_HEIGHT / 2) + 5)
	{
		game->player->x = WINDOW_WIDTH / 2;
		while (game->player->x < (WINDOW_WIDTH / 2) + 5)
		{
			mlx_put_pixel(game->player->img, game->player->x, game->player->y,
				0xFF0000FF);
			game->player->x++;
		}
		game->player->y++;
	}
	// draw_lines_10_degrees(game);

}

void	draw_map2d(t_game *game)
{
	game->pt.y = 0;
	game->pt.mapx = 0;
	game->pt.mapy = 0;
	game->img = (t_image *)malloc(sizeof(t_image));
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "THIS IS CUBE3D", 100);
	game->player->img = mlx_new_image(game->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
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
	draw_player(game);
}

int	main(void)
{
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	game->player = (t_player *)ft_calloc(sizeof(t_player), 1);
	game->i = 0;
	draw_map2d(game);
	mlx_loop_hook(game->mlx, buttons, game);
	mlx_key_hook(game->mlx, draw_lines_10_degrees, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game->player);
	free(game->img);
	free(game);
	return (0);
}
