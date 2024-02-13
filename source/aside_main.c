/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aside_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:53:15 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/12 14:54:04 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int *world_map[]=
// {
// 	(int[]){1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	(int[]){1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

// // void	buttons(void *param)
// // {
// 	// t_game* game = (t_game*)param;
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 	// 	mlx_close_window(game->mlx);
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_W))
// 	// 	game->player->img->instances[0].y -= 5;
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_S))
// 	// 	game->player->img->instances[0].y += 5;
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_A))
// 	// 	game->player->img->instances[0].x -= 5;
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_D))
// 	// 	game->player->img->instances[0].x += 5;
// //}

// void buttons(void *param)
// {
// 	t_game *game = (t_game *)param;

// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) {
// 		mlx_close_window(game->mlx);
// 	}

// 	if (mlx_is_key_down(game->mlx, MLX_KEY_W)) {
// 		// Assuming game->player->img is now t_image*
// 		game->player->img->y -= 5;
// 	}

// 	if (mlx_is_key_down(game->mlx, MLX_KEY_S)) {
// 		game->player->img->y += 5;
// 	}

// 	if (mlx_is_key_down(game->mlx, MLX_KEY_A)) {
// 		game->player->img->x -= 5;
// 	}

// 	if (mlx_is_key_down(game->mlx, MLX_KEY_D)) {
// 		game->player->img->x += 5;
// 	}
// }

// void mlx_draw_line(void *mlx_ptr, int x0, int y0, int x1, int y1, int color)
// {
// 	int dx = abs(x1 - x0);
// 	int dy = abs(y1 - y0);
// 	int sx = x0 < x1 ? 1 : -1;
// 	int sy = y0 < y1 ? 1 : -1;
// 	int err = dx - dy;
// 	int e2;

// 	while (1)
// 	{
// 		mlx_put_pixel(mlx_ptr, x0, y0, color);
// 		if (x0 == x1 && y0 == y1) break;
// 		e2 = 2 * err;
// 		if (e2 > -dy) { 
// 			err -= dy; 
// 			x0 += sx; 
// 		}
// 		if (e2 < dx) { 
// 			err += dx; 
// 			y0 += sy; 
// 		}
// 	}
// }

// int calculate_wall_shade(double wall_dist)
// {
// 	int shade = (int)(255 * (1 - wall_dist));
// 	shade = (shade < 0) ? 0 : (shade > 255) ? 255 : shade;
// 	return shade;
// }

// void cast_ray(t_ray *ray, int *map[MAP_HEIGHT])
// {
// 	int side_dist_x, side_dist_y;
// 	double delta_dist_x, delta_dist_y;
// 	int map_x, map_y;
// 	int step_x, step_y;
// 	int hit = 0;
// 	if (ray->dir_x < 0)
// 	{
// 		step_x = -1;
// 		side_dist_x = (ray->origin.x - floor(ray->origin.x)) * side_dist_y;
// 	}
// 	else
// 	{
// 		step_x = 1;
// 		side_dist_x = (floor(ray->origin.x) + 1.0 - ray->origin.x) * side_dist_y;
// 	}
// 	if (ray->dir_y < 0)
// 	{
// 		step_y = -1;
// 		side_dist_y = (ray->origin.y - floor(ray->origin.y)) * side_dist_x;
// 	}
// 	else
// 	{
// 		step_y = 1;
// 		side_dist_y = (floor(ray->origin.y) + 1.0 - ray->origin.y) * side_dist_x;
// 	}
// 	while (!hit && ray->max_distance > 0)
// 	{
// 		side_dist_x += delta_dist_x;
// 		side_dist_y += delta_dist_y;
// 		map_x = (int)ray->origin.x;
// 		map_y = (int)ray->origin.y;
// 		if (step_x == 1) map_x++;
// 		if (step_y == 1) map_y++;
// 		if (map[map_y][map_x] != ' ')
// 		{
// 			hit = 1;
// 			ray->wall_hit = 1;
// 			if (step_x == -1)
// 				ray->wall_dist = (ray->origin.x - map_x) / ray->dir_x;
// 			else
// 				ray->wall_dist = (map_x - ray->origin.x) / ray->dir_x;
// 		}
// 		if (side_dist_x > side_dist_y)
// 		{
// 			side_dist_x += delta_dist_x;
// 			ray->origin.x += step_x;
// 		}
// 		else
// 		{
// 			side_dist_y += delta_dist_y;
// 			ray->origin.y += step_y;
// 		}
// 		delta_dist_x = fabs(1 / ray->dir_x);
// 		delta_dist_y = fabs(1 / ray->dir_y);
// 	}
// 	// Handle potential edge cases or additional calculations here (optional)
// }

// int get_wall_texture_color(int wall_hit, t_texture wall_texture, double hit_x)
// {
//     int u = (int)(hit_x * wall_texture.width); // Calculate texture u coordinate
//     int v = (int)(wall_hit * wall_texture.height); // Calculate texture v coordinate

//     // Handle edge cases and modulo operations if needed
//     u %= wall_texture.width;
//     v %= wall_texture.height;

//     // Access pixel data using appropriate byte indexing based on color format
//     int color_offset = v * wall_texture.width * 4 + u * 4; // Assuming RGBA format
//     return *(int *)(wall_texture.data + color_offset); // Retrieve color value
// }

// // void set_ray(t_ray *ray, int x, t_vector *player_pos, void *img, t_vector *camera_plane)
// // {
// // 	//t_game	*game;
// // 	double camera_plane_x = cos(player_pos->dir + FOV_ANGLE / 2) * TILE_SIZE;
// // 	double camera_plane_y = sin(player_pos->dir + FOV_ANGLE / 2) * TILE_SIZE;
// // 	double ray_dir_x = x - WINDOW_WIDTH / 2;
// // 	double ray_dir_y = -ray_dir_x * camera_plane_y / camera_plane_x;

// // 	// Normalize ray direction
// // 	double magnitude = sqrt(ray_dir_x * ray_dir_x + ray_dir_y * ray_dir_y);
// // 	ray->dir_x = ray_dir_x / magnitude;
// // 	ray->dir_y = ray_dir_y / magnitude;
// // 	ray->origin.x = player_pos->x;
// // 	ray->origin.y = player_pos->y;
// // 	ray->camera_plane_x = camera_plane_x;
// // 	ray->camera_plane_y = camera_plane_y;
// // 	ray->max_distance = RAY_LENGTH;
// // 	ray->wall_hit = 0; 
// // }

// void set_ray(t_ray *ray, int x, t_vector *player_pos, void *img, t_vector *camera_plane)
// {
//     if (!ray || !player_pos || !camera_plane) {
//         // Handle invalid parameters
//         fprintf(stderr, "Invalid parameters passed to set_ray function\n");
//         return;
//     }

//     // Ensure necessary constants are properly defined and initialized
//     if (TILE_SIZE == 0 || FOV_ANGLE == 0 || WINDOW_WIDTH == 0 || RAY_LENGTH == 0) {
//         // Handle uninitialized constants
//         fprintf(stderr, "Constants are not properly initialized\n");
//         return;
//     }

//     double camera_plane_x = 0.0;
//     double camera_plane_y = 0.0;
//     double ray_dir_x = 0.0;
//     double ray_dir_y = 0.0;

//     // Calculate camera plane values, ensuring no division by zero
//     double angle_offset = player_pos->dir + FOV_ANGLE / 2;
// 	printf("Hiiiiiiiiiiii");
//     if (angle_offset != 0.0) {
//         camera_plane_x = cos(angle_offset) * TILE_SIZE;
//         camera_plane_y = sin(angle_offset) * TILE_SIZE;
//     } else {
//         // Handle division by zero or invalid angle offset
//         fprintf(stderr, "Invalid angle offset for camera plane calculation\n");
//         return;
//     }

//     ray_dir_x = x - WINDOW_WIDTH / 2;
//     ray_dir_y = -ray_dir_x * camera_plane_y / camera_plane_x;

//     // Normalize ray direction
//     double magnitude = sqrt(ray_dir_x * ray_dir_x + ray_dir_y * ray_dir_y);
//     if (magnitude != 0.0) {
//         ray->dir_x = ray_dir_x / magnitude;
//         ray->dir_y = ray_dir_y / magnitude;
//     } else {
//         // Handle division by zero or invalid magnitude
//         fprintf(stderr, "Invalid magnitude for ray direction normalization\n");
//         return;
//     }

//     // Assign other ray properties
//     ray->origin.x = player_pos->x;
//     ray->origin.y = player_pos->y;
//     ray->camera_plane_x = camera_plane_x;
//     ray->camera_plane_y = camera_plane_y;
//     ray->max_distance = RAY_LENGTH;
//     ray->wall_hit = 0; 
// }


// int get_ceiling_texture_color(int x, int y, t_texture *ceiling_texture) {
//     // Use constant color value (modify if needed)
//     return 0xFFFFFFFF; // White ceiling
// }

// int get_floor_texture_color(int x, int y, t_texture *ceiling_texture) {
//     // Use constant color value (modify if needed)
//     return 0xFF0000FF; // White ceiling
// }


// void draw_player(void *param)
// {
// 	t_game *game = (t_game *)param;

// 	game->player = (t_player *)ft_calloc(sizeof(t_player), 1);
// 	game->player->imag = mlx_new_image(game->mlx, 100, 100);
// 	mlx_image_to_window(game->mlx, game->player->imag, WINDOW_WIDTH / 2 - 5, WINDOW_HEIGHT / 2 - 5);
// 	int player_center_x = MAP_WIDTH / 2;
// 	int player_center_y = MAP_HEIGHT / 2;
// 	int crosshair_size = 5;
// 	int crosshair_color = 0x00FFFF00;
// 	mlx_draw_line(game->mlx, player_center_x - crosshair_size, player_center_y,\
// 		player_center_x + crosshair_size, player_center_y, crosshair_color);
// 	mlx_draw_line(game->mlx, player_center_x, player_center_y - crosshair_size,\
// 		player_center_x, player_center_y + crosshair_size, crosshair_color);
// }

// void	draw_map2d(t_game *game)
// {
// 	t_vector camera_plane;
// 	game->pt->y = 0;
// 	game->pt->mapx = 0;
// 	game->pt->mapy = 0;
// 	game->img = (t_image *)malloc(sizeof(t_image));
// 	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "THIS IS CUBE3D", 100);
// 	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	mlx_image_to_window(game->mlx, game->img, 0, 0);
// 	game->pt->y = 0;
// 	for (int y = 0; y < WINDOW_HEIGHT; y++) {
// 		for (int x = 0; x < WINDOW_WIDTH; x++)
// 		{
// 			t_ray ray;
// 			set_ray(&ray, x, &game->player->pos, game->img, &camera_plane);
// 			cast_ray(&ray, world_map);
// 			if (ray.wall_hit)
// 			{
// 				int wall_height = WINDOW_HEIGHT / ray.wall_dist;
// 				int start_y = (WINDOW_HEIGHT - wall_height) / 2;
// 				t_texture wall_texture;
// 				int tex_color = get_wall_texture_color(ray.wall_hit, wall_texture, ray.hit_x);
// 				int shade = calculate_wall_shade(ray.wall_dist);
// 				mlx_draw_line(game->mlx, x, start_y, x, start_y + wall_height, shade * tex_color);
// 			}
// 			else
// 			{
// 				// Ray pointing upwards, hit the ceiling
// 				if (ray.dir_y > 0) {
// 					// Calculate ceiling pixel coordinates
// 					int ceiling_y = 0; // Set to top of screen initially
// 					int tile_y = (int)ray.origin.y; // Use ray origin's y coordinate

// 					// Consider adjusting for ceiling height variation
// 					ceiling_y += (int)(game->ceiling_height * CEILING_SCALE);

// 					// Calculate ceiling pixel x coordinate based on camera plane
// 					int ceiling_x = x;
// 					double ceiling_wall_dist = ray.wall_dist;
// 					double dist_correction = ray.dir_x / ray.dir_y; // Calculate angle-based correction
// 					ceiling_x -= (int)(ceiling_wall_dist * dist_correction);

// 					// Wrap ceiling_x to map width if needed
// 					ceiling_x %= MAP_WIDTH;

// 					// Access ceiling texture color
// 					int ceiling_tex_color = get_ceiling_texture_color(ceiling_x, tile_y, &game->ceiling_texture);

// 					// Draw ceiling line (adjust starting y based on perspective, e.g., using ray.dir_y)
// 					for (int y = 0; y < ceiling_y; y++) {
// 						mlx_put_pixel(game->img, x, ceiling_y - y, ceiling_tex_color);
// 					}
// 				}
// 				else
// 				{
// 					// Ray pointing downwards, hit the floor
// 					// Calculate floor pixel coordinates
// 					int floor_y = WINDOW_HEIGHT - 1; // Set to bottom of screen initially
// 					int tile_y = (int)ray.origin.y; // Use ray origin's y coordinate

// 					// Consider adjusting for player height and floor level variation
// 					floor_y -= (int)(game->player->pos.y * FLOOR_SCALE);
// 					tile_y = MAP_HEIGHT - 1 - tile_y; // Invert y based on map layout

// 					// Calculate floor pixel x coordinate based on camera plane
// 					int floor_x = x;
// 					double floor_wall_dist = ray.wall_dist;
// 					double dist_correction = ray.dir_x / ray.dir_y; // Calculate angle-based correction
// 					floor_x -= (int)(floor_wall_dist * dist_correction);

// 					// Wrap floor_x to map width if needed
// 					floor_x %= MAP_WIDTH;

// 					// Access floor texture color
// 					int floor_tex_color = get_floor_texture_color(floor_x, tile_y, &game->floor_texture);

// 					// Draw floor line
// 					mlx_draw_line(game->mlx, x, floor_y, x, WINDOW_HEIGHT, floor_tex_color);
// 				}
// 			}
// 		}
// 	}
// }

// int	main(void)
// {
// 	t_game	*game;

// 	game = (t_game *)ft_calloc(sizeof(t_game), 1);
// 	game->pt = (t_point *)ft_calloc(sizeof(t_point), 1);
// 	game->player_pos = (t_vector *)ft_calloc(sizeof(t_vector), 1);
// 	draw_map2d(game);
// 	draw_player(game);
// 	mlx_loop_hook(game->mlx, buttons, game);
// 	mlx_loop(game->mlx);
// 	free(game->player);
// 	free(game->img);
// 	free(game);
// 	return (0);
// }



// void draw_player(void *param)
// {
// 	t_game *game = (t_game *)param;

// 	game->player = (t_player *)ft_calloc(sizeof(t_player), 1);
// 	game->player->img = mlx_new_image(game->mlx, 100, 100);  // Adjust image size for circle
// 	mlx_image_to_window(game->mlx, game->player->img, WINDOW_WIDTH / 2 - 5, WINDOW_HEIGHT / 2 - 5);  // Center the circle

// 	int radius = 2;
// 	int centerX = 2;
// 	int centerY = 2;
// 	int x = radius;
// 	int y = 0;
// 	int radiusError = 1 - x;

// 	while (x >= y)
// 	{
// 		mlx_put_pixel(game->player->img, centerX + x, centerY + y, 0xFF0000FF);
// 		mlx_put_pixel(game->player->img, centerX - x, centerY + y, 0xFF0000FF);
// 		mlx_put_pixel(game->player->img, centerX + x, centerY - y, 0xFF0000FF);
// 		mlx_put_pixel(game->player->img, centerX - x, centerY - y, 0xFF0000FF);
// 		mlx_put_pixel(game->player->img, centerX + y, centerY + x, 0xFF0000FF);
// 		mlx_put_pixel(game->player->img, centerX - y, centerY + x, 0xFF0000FF);
// 		mlx_put_pixel(game->player->img, centerX + y, centerY - x, 0xFF0000FF);
// 		mlx_put_pixel(game->player->img, centerX - y, centerY - x, 0xFF0000FF);

// 		y++;
// 		if (radiusError < 0)
// 		{
// 			radiusError += 2 * y + 1;
// 		}
// 		else
// 		{
// 			x--;
// 			radiusError += 2 * (y - x + 1);
// 		}
// 	}
// }