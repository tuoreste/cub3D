/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:14 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/14 19:31:13 by aguediri         ###   ########.fr       */
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

void draw_lines_10_degrees(mlx_key_data_t keydata, void *param) {
    t_game *game = (t_game*)param;
    int x1 = game->player->x;
    int y1 = game->player->y;
    int x_center = WINDOW_WIDTH / 2;
    int y_center = WINDOW_HEIGHT / 2;
    game->radius = 50;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        game->player->y -= 5;
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        game->player->y += 5;
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        game->player->x -= 5;
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        game->player->x += 5;
    if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) {
        game->i+=10;
        // for (int angle = 0 + game->i; angle < 90 + game->i; angle += 10) {
            game->x2 = x1 + game->radius * cos(game->i * M_PI / 180);
            game->y2 = y1 + game->radius * sin(game->i * M_PI / 180);
            getcollpoint(game, x1, y1);
            mlx_loop_hook(game->mlx, draw_line, game);
        }
    // }
    if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) {
        game->i-=10;
        // for (int angle = 0 + game->i; angle < 90 + game->i; angle += 10) {
            game->x2 = x_center + game->radius * cos(game->i * M_PI / 180);
            game->y2 = y_center + game->radius * sin(game->i * M_PI / 180);
            getcollpoint(game, x1, y1);
            mlx_loop_hook(game->mlx, draw_line, game);
        // }
    }
}
int is_collision_with_wall(t_game *game, int x1, int y1, int x2, int y2) {
    for (int x = x1; x != x2; x += (x2 - x1 > 0) ? 1 : -1) {
        for (int y = y1; y != y2; y += (y2 - y1 > 0) ? 1 : -1) {
            int mapx = x * MAP_WIDTH / WINDOW_WIDTH;
            int mapy = y * MAP_HEIGHT / WINDOW_HEIGHT;
            if (world_map[mapx][mapy] == 1) {
                return 1;
            }
        }
    }
    return 0;
}
void getcollpoint(t_game *game, int x1, int y1)
{
    if (x1 <= game->x2 && y1 <= game->y2)
    {    while (!is_collision_with_wall(game, x1, y1, game->x2, game->y2))
        {
            game->x2--;
            game->y2--;
        }
    }
    else if (x1 >= game->x2 && y1 >= game->y2)
    {    while (!is_collision_with_wall(game, x1, y1, game->x2, game->y2))
        {
            game->x2--;
            game->y2++;
        }
    }
    else if (x1 <= game->x2 && y1 >= game->y2)
    {    while (!is_collision_with_wall(game, x1, y1, game->x2, game->y2))
        {
            game->x2++;
            game->y2++;
        }
    }
    else if (x1 >= game->x2 && y1 <= game->y2)
    {    while (!is_collision_with_wall(game, x1, y1, game->x2, game->y2))
        {
            game->x2++;
            game->y2--;
        }
    }
}

void draw_line(void *param) {
    
    t_game *game = (t_game*)param;
    int x1 = game->player->x;
    int y1 = game->player->y;
    int x2 = game->x2;
    int y2 = game->y2;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {
        mlx_put_pixel(game->img, x1 , y1 , 0xFF0000FF);

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

void draw_player(void *param) {
    t_game *game = (t_game *)param;
    int x = game->player->x;
    int y = game->player->y;
    // game->player->y = WINDOW_HEIGHT / 2;
    while (y < game->player->y + 5) {
         x = game->player->x;
        while (x < game->player->x + 5) {
            mlx_put_pixel(game->img, game->player->x, game->player->y, 0xFF0000FF);
            x++;
        }
        y++;
    }

}

void draw_map2d(void *param) {
    t_game *game = (t_game*)param;
    game->pt.y = 0;
    game->pt.mapx = 0;
    game->pt.mapy = 0;

    game->pt.y = 0;
    while (game->pt.y < WINDOW_HEIGHT) {
        game->pt.x = 0;
        while (game->pt.x < WINDOW_WIDTH) {
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

int main(void) {
    t_game *game = (t_game *)malloc(sizeof(t_game));
    game->player = (t_player *)malloc(sizeof(t_player));
    game->i = 0;
    game->player->x = WINDOW_WIDTH / 2;
    game->player->y = WINDOW_HEIGHT / 2;
    game->img = (t_image *)malloc(sizeof(t_image));
    game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "THIS IS CUBE3D", 100);
    game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    mlx_image_to_window(game->mlx, game->img, 0, 0);
    draw_map2d(game);
    // draw_player(game);
    mlx_loop_hook(game->mlx, draw_map2d, game);
    mlx_loop_hook(game->mlx, draw_player, game);
    mlx_key_hook(game->mlx, draw_lines_10_degrees, game);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
    free(game->player);
    free(game->img);
    free(game);
    return (0);
}