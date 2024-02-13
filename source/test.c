
// void	rotate(t_vector *vectors, short sign)
// {
// 	double	cos_a;
// 	double	sin_a;
// 	double	old_dir_x;

// 	cos_a = cos(sign * ROT);
// 	sin_a = sin(sign * ROT);
// 	old_dir_x = vectors->x;
// 	vectors->x = vectors->x * cos_a - vectors->y * sin_a;
// 	vectors->y = old_dir_x * sin_a + vectors->y * cos_a;
// }

// void mlx_draw_line(void *mlx_ptr, int x0, int y0, int x1, int y1, int color)
// {
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;

// 	if (x0 < 0 || x0 >= WINDOW_WIDTH || y0 < 0 || y0 >= WINDOW_HEIGHT ||
// 		x1 < 0 || x1 >= WINDOW_WIDTH || y1 < 0 || y1 >= WINDOW_HEIGHT)
// 		return ;
// 	dx = abs(x1 - x0);
// 	dy = abs(y1 - y0);
// 	if (x0 < x1)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (y0 < y1)
// 		sy = 1;
// 	else
// 		sy = -1;
// 	if (dx > dy)
// 		err = dx / 2;
// 	else
// 		err = -dy / 2;
// 	while (1)
// 	{
// 		if (x0 >= 0 && x0 < WINDOW_WIDTH && y0 >= 0 && y0 < WINDOW_HEIGHT)
// 			mlx_put_pixel(mlx_ptr, x0, y0, color);
// 		if (x0 == x1 && y0 == y1)
// 			break ;
// 		e2 = err;
// 		if (e2 > -dx)
// 		{
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		if (e2 < dy)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }

// void	buttons(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->mlx);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
// 		game->player->img->instances[0].y -= 5;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
// 		game->player->img->instances[0].y += 5;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
// 		game->player->img->instances[0].x -= 5;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
// 		game->player->img->instances[0].x += 5;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
// 	{
// 		double old_dir_x = game->player->dir.x;
// 		game->player->dir.x = game->player->dir.x * cos(-ROT) - game->player->dir.y * sin(-ROT);
// 		game->player->dir.y = old_dir_x * sin(-ROT) + game->player->dir.y * cos(-ROT);
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
// 	{
// 		double old_dir_x = game->player->dir.x;
// 		game->player->dir.x = game->player->dir.x * cos(ROT) - game->player->dir.y * sin(ROT);
// 		game->player->dir.y = old_dir_x * sin(ROT) + game->player->dir.y * cos(ROT);
// 	}
// }

// void	draw_player(void *param)
// {
// 	t_game	*game;
// 	int		x;
// 	int		y;
// 	int		radiusError;
// 	int		end_x;
// 	int		end_y;

// 	game = (t_game *)param;
// 	game->player->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	int radius = 5;
// 	int centerX = WINDOW_WIDTH / 2;
// 	int centerY = WINDOW_HEIGHT / 2;
// 	x = radius;
// 	y = 0;
// 	radiusError = 1 - x;
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
// 	double angle = atan2(game->player->dir.y, game->player->dir.x);
// 	for (int i = 0; i < WINDOW_WIDTH; i++) {
// 		double ray_x = game->player->pos.x + i * cos(angle);
// 		double ray_y = game->player->pos.y + i * sin(angle);
// 		if (ray_x >= 0 && ray_y >= 0 && ray_x < MAP_WIDTH && ray_y < MAP_HEIGHT)
// 		{
// 			mlx_draw_line(game->mlx, centerX, centerY, ray_x, ray_y, 0xFF0000FF);
// 			break;
// 		}
// 	}
// }

// // void	draw_map2d(t_game *game)
// // {
// // 	game->pt.y = 0;
// // 	game->pt.mapx = 0;
// // 	game->pt.mapy = 0;
// // 	game->img = (t_image *)malloc(sizeof(t_image));
// // 	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "THIS IS CUBE3D", 100);
// // 	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// // 	mlx_image_to_window(game->mlx, game->img, 0, 0);
// // 	game->player->pos.x = 5;
// // 	game->player->pos.y = 5;
// // 	game->player->dir.x = 1;
// // 	game->player->dir.y = 0;
// // 	game->pt.y = 0;
// // 	while (game->pt.y < WINDOW_HEIGHT)
// // 	{
// // 		game->pt.x = 0;
// // 		while (game->pt.x < WINDOW_WIDTH)
// // 		{
// // 			game->pt.mapx = game->pt.x * MAP_WIDTH / WINDOW_WIDTH;
// // 			game->pt.mapy = game->pt.y * MAP_HEIGHT / WINDOW_HEIGHT;
// // 			if (world_map[game->pt.mapx][game->pt.mapy] == 1)
// // 				mlx_put_pixel(game->img, game->pt.x, game->pt.y, 0xFFFFFFFF);
// // 			else
// // 				mlx_put_pixel(game->img, game->pt.x, game->pt.y, 0x00000000);
// // 			game->pt.x++;
// // 		}
// // 		game->pt.y++;
// // 	}
// // }

// void draw_map2d(t_game *game)
// {
// 	game->pt.y = 0;
// 	game->pt.mapx = 0;
// 	game->pt.mapy = 0;
// 	game->player->pos.x = 5;
// 	game->player->pos.y = 5;
// 	game->player->dir.x = 1;
// 	game->player->dir.y = 0;
// 	game->img = (t_image *)calloc(sizeof(t_image), 1);
// 	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "THIS IS CUBE3D", 100);
// 	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	mlx_image_to_window(game->mlx, game->img, 0, 0);

// 	// Check if game->player is initialized
// 	if (game->player == NULL) {
// 		// Initialize game->player if not already initialized
// 		game->player = (t_player *)malloc(sizeof(t_player));
// 		if (game->player == NULL) {
// 			// Handle allocation failure
// 			fprintf(stderr, "Error: Memory allocation failed for game->player\n");
// 			exit(EXIT_FAILURE);
// 		}
// 		// Initialize game->player fields
// 	}

// 	game->pt.y = 0;
// 	while (game->pt.y < WINDOW_HEIGHT) {
// 		game->pt.x = 0;
// 		while (game->pt.x < WINDOW_WIDTH) {
// 			game->pt.mapx = game->pt.x * MAP_WIDTH / WINDOW_WIDTH;
// 			game->pt.mapy = game->pt.y * MAP_HEIGHT / WINDOW_HEIGHT;
// 			if (world_map[game->pt.mapx][game->pt.mapy] == 1)
// 				mlx_put_pixel(game->img, game->pt.x, game->pt.y, 0xFFFFFFFF);
// 			else
// 				mlx_put_pixel(game->img, game->pt.x, game->pt.y, 0x00000000);
// 			game->pt.x++;
// 		}
// 		game->pt.y++;
// 	}
// }


// int	main(void)
// {
// 	t_game	*game;

// 	game = (t_game *)ft_calloc(sizeof(t_game), 1);
// 	game->player = (t_player *)ft_calloc(sizeof(t_player), 1);
// 	game->vec = (t_vector *)ft_calloc(sizeof(t_vector), 1);
// 	draw_map2d(game);
// 	draw_player(game);
// 	mlx_loop_hook(game->mlx, buttons, game);
// 	mlx_loop(game->mlx);
//     //mlx_destroy_display(game->mlx);
// 	free(game->player);
// 	free(game->img);
// 	free(game);
// 	return (0);
// }