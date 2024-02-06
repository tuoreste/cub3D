// void	map_scan(void)
// {

// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + ((y * data->line_len) + (x * (data->bits_per_pixel/8)));
// 	*(unsigned int *)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	t_data	*img = NULL;

// 	img = (t_data *)malloc(sizeof(t_data));
// 	mlx = mlx_init(1920, 1080, "THIS IS CUBE3D", 100);
// 	img->img = mlx_new_image(mlx, 1920, 1080);
// 	int i = 0;
// 	mlx_image_to_window(mlx, img->img, 0, 0);
// 	while (i++ < 1000)
// 		mlx_put_pixel(img->img, i, i, 0x00FF00FF);
// 	mlx_loop(mlx);
// }

// int	main(int argc, char *argv[])
// {
// 	double	posX;
// 	double	posY;
// 	double	dirX;
// 	double	dirY;
// 	double	planeX;
// 	double	planeY;
// 	int		x;
// 	double	cameraX;
// 	double	rayDirX;
// 	double	rayDirY;
// 	int		mapX;
// 	int		mapY;
// 	double	sideDistX;
// 	double	sideDistY;
// 	double	deltaDistX;
// 	double	deltaDistY;
// 	double	perpWallDist;
// 	int		stepX;
// 	int		stepY;
// 	int		hit;
// 	int		side;
// 	int		lineHeight;
// 	int		drawStart;
// 	int		drawEnd;
// 			ColorRGB color;
// 	double	oldDirX;
// 	double	oldPlaneX;
// 	double	oldDirX;
// 	double	oldPlaneX;
// 	void	*mlx;

// 	posX = 22;
// 	posY = 12;
// 	dirX = -1;
// 	dirY = 0;
// 	planeX = 0;
// 	planeY = 0.66;
// 	double time = 0; //time of current frame
//   	double oldTime = 0; //time of previous frame
// 	mlx = mlx_init(SCREEN_W, SCREEN_H, "Raycaster", 0);
// 	while (!done())
// 	{
// 		x = 0;
// 		while (x < w)
// 		{
// 			cameraX = 2 * x / double (w) - 1;
// 			rayDirX = dirX + planeX * cameraX;
// 			rayDirY = dirY + planeY * cameraX;
// 			deltaDistX = abs(1 / rayDirX);
// 			deltaDistY = abs(1 / rayDirY);
// 			if (rayDirX == 0)
// 				deltaDistX = 1e30;
// 			else
// 				deltaDistX = abs(1 / rayDirX);
// 			if (rayDirY == 0)
// 				deltaDistY = 1e30;
// 			else
// 				deltaDistX = abs(1 / rayDirY);
// 			mapX = int (posX);
// 			mapY = int (posY);
// 			hit = 0;
// 			if (rayDirX < 0)
// 			{
// 				stepX = -1;
// 				sideDistX = (posX - mapX) * deltaDistX;
// 			}
// 			else
// 			{
// 				stepX = 1;
// 				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// 			}
// 			if (rayDirY < 0)
// 			{
// 				stepY = -1;
// 				sideDistY = (posY - mapY) * deltaDistY;
// 			}
// 			else
// 			{
// 				stepY = 1;
// 				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// 			}
// 			while (hit == 0)
// 			{
// 				if (sideDistX < sideDistY)
// 				{
// 					sideDistX += deltaDistX;
// 					mapX += stepX;
// 					side = 0;
// 				}
// 				else
// 				{
// 					sideDistY += deltaDistY;
// 					mapY += stepY;
// 					side = 1;
// 				}
// 				if (worldMap[mapX][mapY] > 0)
// 					hit = 1;
// 			}
// 			if (side == 0)
// 				perpWallDist = (sideDistX - deltaDistX);
// 			else
// 				perpWallDist = (sideDistY - deltaDistY);
// 			lineHeight = (int)(h / perpWallDist);
// 			// calculate lowest and highest pixel to fill in current stripe
// 			drawStart = -lineHeight / 2 + h / 2;
// 			if (drawStart < 0)
// 				drawStart = 0;
// 			drawEnd = lineHeight / 2 + h / 2;
// 			if (drawEnd >= h)
// 				drawEnd = h - 1;
// 			switch (worldMap[mapX][mapY])
// 			{
// 			case 1:
// 				color = RGB_Red;
// 				break ; // red
// 			case 2:
// 				color = RGB_Green;
// 				break ; // green
// 			case 3:
// 				color = RGB_Blue;
// 				break ; // blue
// 			case 4:
// 				color = RGB_White;
// 				break ; // white
// 			default:
// 				color = RGB_Yellow;
// 				break ; // yellow
// 			}
// 			// give x and y sides different brightness
// 			if (side == 1)
// 				color = color / 2;
// 			// draw the pixels of the stripe as a vertical line
// 			verLine(x, drawStart, drawEnd, color);
// 			oldTime = time;
// 			time = getTicks();
// 			double frameTime = (time - oldTime) / 1000.0;
// 				// frameTime is the time this frame has taken, in seconds
// 			print(1.0 / frameTime);                       // FPS counter
// 			redraw();
// 			cls();
// 			// speed modifiers
// 			double moveSpeed = frameTime * 5.0;
// 				// the constant value is in squares/second
// 			double rotSpeed = frameTime * 3.0;
// 				// the constant value is in radians/second
// 			readKeys();
// 			// move forward if no wall in front of you
// 			if (keyDown(SDLK_UP))
// 			{
// 				if (worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false)
// 					posX += dirX * moveSpeed;
// 				if (worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false)
// 					posY += dirY * moveSpeed;
// 			}
// 			// move backwards if no wall behind you
// 			if (keyDown(SDLK_DOWN))
// 			{
// 				if (worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false)
// 					posX -= dirX * moveSpeed;
// 				if (worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false)
// 					posY -= dirY * moveSpeed;
// 			}
// 			// rotate to the right
// 			if (keyDown(SDLK_RIGHT))
// 			{
// 				// both camera direction and camera plane must be rotated
// 				oldDirX = dirX;
// 				dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
// 				dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
// 				oldPlaneX = planeX;
// 				planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
// 				planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// 			}
// 			// rotate to the left
// 			if (keyDown(SDLK_LEFT))
// 			{
// 				// both camera direction and camera plane must be rotated
// 				oldDirX = dirX;
// 				dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
// 				dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
// 				oldPlaneX = planeX;
// 				planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
// 				planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
// 			}
// 			x++;
// 		}
// 	}
// }