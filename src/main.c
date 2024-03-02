/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:02:26 by aguediri          #+#    #+#             */
/*   Updated: 2024/03/02 16:12:54 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_exit(t_map *data)  
{
 int i = 0;
 while (data->map[i])
  free(data->map[i++]);
 free(data->map);
//  free(mlx->dt);
 free(data->mlx.player);
 free(data->mlx.ray);
 mlx_delete_image(data->mlx.mlx_p, data->mlx.img);
 mlx_close_window(data->mlx.mlx_p);
 mlx_terminate(data->mlx.mlx_p);
 printf("Game closed\n");
 exit(0);
}

void ft_initkeys(mlx_key_data_t keydata, t_map *data)
{
 if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
  data->mlx.player->l_r = 0;
 else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
  data->mlx.player->l_r = 0;
 else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
  data->mlx.player->u_d = 0;
 else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
  data->mlx.player->u_d = 0;
 else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
  data->mlx.player->rot = 0;
 else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
  data->mlx.player->rot = 0;
}

void mlx_key(mlx_key_data_t keydata, void *ml)
{
 t_map *data;

 data = ml;
 if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
  ft_exit(data);
 else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
  data->mlx.player->l_r = -1;
 else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
  data->mlx.player->l_r = 1;
 else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
  data->mlx.player->u_d = -1;
 else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
  data->mlx.player->u_d = 1;
 else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
  data->mlx.player->rot = -1;
 else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
  data->mlx.player->rot = 1;
 ft_initkeys(keydata, data);
}

void rotate_player(t_map *data, int i)
{
 if (i == 1)
 {
  data->mlx.player->angle += ROTATION_SPEED;
  if (data->mlx.player->angle > 2 * M_PI)
   data->mlx.player->angle -= 2 * M_PI;
 }
 else
 {
  data->mlx.player->angle -= ROTATION_SPEED;
  if (data->mlx.player->angle < 0)
   data->mlx.player->angle += 2 * M_PI;
 }
}

void move_player(t_map *data, double move_x, double move_y)
{
 int  map_grid_y;
 int  map_grid_x;
 int  new_x;
 int  new_y;

 new_x = roundf(data->mlx.player->player_x + move_x);
 new_y = roundf(data->mlx.player->player_y + move_y);
 map_grid_x = (new_x / TILE_SIZE);
 map_grid_y = (new_y / TILE_SIZE);
 if (data->map[map_grid_y][map_grid_x] != '1' && \
 (data->map[map_grid_y][data->mlx.player->player_x / TILE_SIZE] != '1' && \
 data->map[data->mlx.player->player_y / TILE_SIZE][map_grid_x] != '1'))
 {
  data->mlx.player->player_x = new_x;
  data->mlx.player->player_y = new_y;
 }
}

void hook(t_map *data, double move_x, double move_y)
{
 if (data->mlx.player->rot == 1)
  rotate_player(data, 1);
 if (data->mlx.player->rot == -1)
  rotate_player(data, 0);
 if (data->mlx.player->l_r == 1)
 {
  move_x = -sin(data->mlx.player->angle) * PLAYER_SPEED;
  move_y = cos(data->mlx.player->angle) * PLAYER_SPEED;
 }
 if (data->mlx.player->l_r == -1)
 {
  move_x = sin(data->mlx.player->angle) * PLAYER_SPEED;
  move_y = -cos(data->mlx.player->angle) * PLAYER_SPEED;
 }
 if (data->mlx.player->u_d == 1)
 {
  move_x = cos(data->mlx.player->angle) * PLAYER_SPEED;
  move_y = sin(data->mlx.player->angle) * PLAYER_SPEED;
 }
 if (data->mlx.player->u_d == -1)
 {
  move_x = -cos(data->mlx.player->angle) * PLAYER_SPEED;
  move_y = -sin(data->mlx.player->angle) * PLAYER_SPEED;
 }
 move_player(data, move_x, move_y);
}


void put_pixel_accordingly(t_map *data, int x, int y, int color)
{
 if (x < 0)
  return ;
 else if (x >= S_W)
  return ;
 if (y < 0)
  return ;
 else if (y >= S_H)
  return ;
 mlx_put_pixel(data->mlx.img, x, y, color);
}

float fix_angles(float angle)
{
 if (angle < 0)
  angle += (2 * M_PI);
 if (angle > (2 * M_PI))
  angle -= (2 * M_PI);
 return (angle);
}

void draw_floor_ceiling(t_map *data, int ray, int t_pix, int b_pix)
{
 int  i;
 int  c;

 i = b_pix;
 while (i < S_H)
  put_pixel_accordingly(data, ray, i++, 0xB99470FF);
 i = 0;
 while (i < t_pix)
  put_pixel_accordingly(data, ray, i++, 0x89CFF3FF);
}

int get_color(t_mlx *mlx, int f)
{
 mlx->ray->r_angle = fix_angles(mlx->ray->r_angle);
 if (f == 0)
 {
  if (mlx->ray->r_angle > M_PI / 2 && mlx->ray->r_angle < 3 * (M_PI / 2))
   return (0xB5B5B5FF);
  else
   return (0xB5B5B5FF);
 }
 else
 {
  if (mlx->ray->r_angle > 0 && mlx->ray->r_angle < M_PI)
   return (0xF5F5F5FF);
  else
   return (0xF5F5F5FF);
 }
}
mlx_texture_t	*get_texture(t_map *data, int flag)
{
	data->mlx.ray->r_angle = fix_angles(data->mlx.ray->r_angle);
	if (flag == 0)
	{
		if (data->mlx.ray->r_angle > M_PI / 2 && data->mlx.ray->r_angle < 3 * (M_PI / 2))
			return (data->texture->ea);
		else
			return (data->texture->so);
	}
	else
	{
		if (data->mlx.ray->r_angle > 0 && data->mlx.ray->r_angle < M_PI)
			return (data->texture->we);
		else
			return (data->texture->no);
	}
}
double	get_x_o(mlx_texture_t	*texture, t_map *data)
{
	double	x_o;

	if (data->mlx.ray->f == 1)
		x_o = (int)fmodf((data->mlx.ray->horiz_x * \
		(texture->width / TILE_SIZE)), texture->width);
	else
		x_o = (int)fmodf((data->mlx.ray->vert_y * \
		(texture->width / TILE_SIZE)), texture->width);
	return (x_o);
}
int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

void draw_wall(t_map *data, int ray, int t_pix, int b_pix, double wall_h)
{
 int color;
 double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

 texture = get_texture(data, data->mlx.ray->f);
 arr = (uint32_t *)texture->pixels;
 factor = (double)texture->height / wall_h;
 x_o = get_x_o(texture, data);
//  while (t_pix < b_pix)
//   put_pixel_accordingly(mlx, ray, t_pix++, color);
y_o = (t_pix - (S_H / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		put_pixel_accordingly(data, data->mlx.ray->index, t_pix, reverse_bytes \
		(arr[(int)y_o * texture->width + (int)x_o]));
		y_o += factor;
		t_pix++;
	}
}

void render_wall(t_map *data, int ray)
{
 double wall_h;
 double b_pix;
 double t_pix;

 data->mlx.ray->dist *= cos(fix_angles(data->mlx.ray->r_angle - data->mlx.player->angle));
 wall_h = (TILE_SIZE / data->mlx.ray->dist) * ((S_W / 2) / tan(data->mlx.player->fov / 2));
 b_pix = (S_H / 2) + (wall_h / 2);
 t_pix = (S_H / 2) - (wall_h / 2);
 if (b_pix > S_H)
  b_pix = S_H;
 if (t_pix < 0)
  t_pix = 0;
  data->mlx.ray->index = ray;
 draw_wall(data, ray, t_pix, b_pix, wall_h);
 draw_floor_ceiling(data, ray, t_pix, b_pix);
}


int check_circle(float angle, char c)
{
 if (c == 'x')
 {
  if (angle > 0 && angle < M_PI)
   return (1);
 }
 else if (c == 'y')
 {
  if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
   return (1);
 }
 return (0);
}

int check_intersection(float angle, float *inter, float *step, int is_horizon)
{
 if (is_horizon)
 {
  if (angle > 0 && angle < M_PI)
  {
   *inter += TILE_SIZE;
   return (-1);
  }
  *step *= -1;
 }
 else
 {
  if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
  {
   *inter += TILE_SIZE;
   return (-1);
  }
  *step *= -1;
 }
 return (1);
}

int check_wall_hit(float x, float y, t_map *dt)
{
 int  x_m;
 int  y_m;

 if (x < 0 || y < 0)
  return (0);
 x_m = floor (x / TILE_SIZE);
 y_m = floor (y / TILE_SIZE);
 if ((y_m >= dt->h_map || x_m >= dt->w_map))
  return (0);
 if (dt->map[y_m] && x_m <= (int)strlen(dt->map[y_m]))
  if (dt->map[y_m][x_m] == '1')
   return (0);
 return (1);
}

float get_horizontal_int(t_map *data, float angl)
{
 float h_x;
 float h_y;
 float x_step;
 float y_step;
 int  pixel;

 y_step = TILE_SIZE;
 x_step = TILE_SIZE / tan(angl);
 h_y = floor(data->mlx.player->player_y / TILE_SIZE) * TILE_SIZE;
 pixel = check_intersection(angl, &h_y, &y_step, 1);
 h_x = data->mlx.player->player_x + (h_y - data->mlx.player->player_y) / tan(angl);
 if ((check_circle(angl, 'y') && x_step > 0) || (!check_circle(angl, 'y') && x_step < 0))
  x_step *= -1;
 while (check_wall_hit(h_x, h_y - pixel, data))
 {
  h_x += x_step;
  h_y += y_step;
 }
 	data->mlx.ray->horiz_x = h_x;
	data->mlx.ray->horiz_y = h_y;
 return (sqrt(pow(h_x - data->mlx.player->player_x, 2) + pow(h_y - data->mlx.player->player_y, 2)));
}

float get_vertical_int(t_map *data, float angl)
{
 float v_x;
 float v_y;
 float x_step;
 float y_step;
 int  pixel;

 x_step = TILE_SIZE; 
 y_step = TILE_SIZE * tan(angl);
 v_x = floor(data->mlx.player->player_x / TILE_SIZE) * TILE_SIZE;
 pixel = check_intersection(angl, &v_x, &x_step, 0);
 v_y = data->mlx.player->player_y + (v_x - data->mlx.player->player_x) * tan(angl);
 if ((check_circle(angl, 'x') && y_step < 0) || (!check_circle(angl, 'x') && y_step > 0))
  y_step *= -1;
 while (check_wall_hit(v_x - pixel, v_y, data))
 {
  v_x += x_step;
  v_y += y_step;
 }
 	data->mlx.ray->horiz_x = v_x;
	data->mlx.ray->horiz_y = v_y;
 return (sqrt(pow(v_x - data->mlx.player->player_x, 2) + pow(v_y - data->mlx.player->player_y, 2)));
}

void raycast(t_map *data)
{
 double h_inter;
 double v_inter;
 int  ray;

 ray = 0;
 data->mlx.ray->r_angle = data->mlx.player->angle - (data->mlx.player->fov / 2);
 while (ray < S_W)
 {
  data->mlx.ray->f = 0;
  h_inter = get_horizontal_int(data, fix_angles(data->mlx.ray->r_angle));
  v_inter = get_vertical_int(data, fix_angles(data->mlx.ray->r_angle));
  if (v_inter <= h_inter)
   data->mlx.ray->dist = v_inter;
  else
  {
   data->mlx.ray->dist = h_inter;
   data->mlx.ray->f = 1;
  }
  render_wall(data, ray);
  ray++;
  data->mlx.ray->r_angle += (data->mlx.player->fov / S_W);
 }
}


void game_loop(void *ml)
{
 t_map *data;

 data = ml;
 mlx_delete_image(data->mlx.mlx_p, data->mlx.img);
 data->mlx.img = mlx_new_image(data->mlx.mlx_p, S_W, S_H);
 hook(data, 0, 0);
 raycast(data);
 mlx_image_to_window(data->mlx.mlx_p, data->mlx.img, 0, 0);
}

void init_the_player(t_map *data)
{
 data->mlx.player->player_x = data->p_x * TILE_SIZE + TILE_SIZE / 2;
 data->mlx.player->player_y = data->p_y * TILE_SIZE + TILE_SIZE / 2;
 data->mlx.player->fov = (FOV * M_PI) / 180;
 data->mlx.player->angle = M_PI;

}
void get_texture_data(t_map *data)
{
  data->texture = (t_texture *)ft_calloc(1, sizeof(t_texture)); 
  data->texture->ea = mlx_load_png(data->east);
  data->texture->so = mlx_load_png(data->south);
  data->texture->no = mlx_load_png(data->north);
  data->texture->we = mlx_load_png(data->west);
}
void start_the_game(t_map *dt)
{

 dt->mlx.player = calloc(1, sizeof(t_player));
 dt->mlx.ray = calloc(1, sizeof(t_ray));
 dt->mlx.mlx_p = mlx_init(S_W, S_H, "Cub3D", 0);
 get_texture_data(dt);
 init_the_player(dt);
 mlx_loop_hook(dt->mlx.mlx_p, &game_loop, dt);
 mlx_key_hook(dt->mlx.mlx_p, &mlx_key, dt);
 mlx_loop(dt->mlx.mlx_p);
 ft_exit(dt);
}

void v()
{
 system("leaks cub3D");
}
int	main(int argc, char **argv)
{
	t_map	*data;
	if (argc != 2 || ft_strnstr(argv[1], ".cub", 4))
		printf("error");
	data = get_map_data(argv[1]);
	printf("\n\n\n%d\n\n\n",data->h_map);
	printf("\n\n\n%d\n\n\n",data->w_map);
 	atexit(v);
	start_the_game(data);
	if (!checkmap(data->map))
		printf("not valid");
	else
		printf("valid af");
}