/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:02:26 by aguediri          #+#    #+#             */
/*   Updated: 2024/03/01 23:25:50 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_exit(t_mlx *mlx)  
{
 int i = 0;
 while (mlx->dt->map[i])
  free(mlx->dt->map[i++]);
 free(mlx->dt->map);
 free(mlx->dt);
 free(mlx->player);
 free(mlx->ray);
 mlx_delete_image(mlx->mlx_p, mlx->img);
 mlx_close_window(mlx->mlx_p);
 mlx_terminate(mlx->mlx_p);
 printf("Game closed\n");
 exit(0);
}

void ft_initkeys(mlx_key_data_t keydata, t_mlx *mlx)
{
 if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
  mlx->player->l_r = 0;
 else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
  mlx->player->l_r = 0;
 else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
  mlx->player->u_d = 0;
 else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
  mlx->player->u_d = 0;
 else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
  mlx->player->rot = 0;
 else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
  mlx->player->rot = 0;
}

void mlx_key(mlx_key_data_t keydata, void *ml)
{
 t_mlx *mlx;

 mlx = ml;
 if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
  ft_exit(mlx);
 else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
  mlx->player->l_r = -1;
 else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
  mlx->player->l_r = 1;
 else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
  mlx->player->u_d = -1;
 else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
  mlx->player->u_d = 1;
 else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
  mlx->player->rot = -1;
 else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
  mlx->player->rot = 1;
 ft_initkeys(keydata, mlx);
}

void rotate_player(t_mlx *mlx, int i)
{
 if (i == 1)
 {
  mlx->player->angle += ROTATION_SPEED;
  if (mlx->player->angle > 2 * M_PI)
   mlx->player->angle -= 2 * M_PI;
 }
 else
 {
  mlx->player->angle -= ROTATION_SPEED;
  if (mlx->player->angle < 0)
   mlx->player->angle += 2 * M_PI;
 }
}

void move_player(t_mlx *mlx, double move_x, double move_y)
{
 int  map_grid_y;
 int  map_grid_x;
 int  new_x;
 int  new_y;

 new_x = roundf(mlx->player->player_x + move_x);
 new_y = roundf(mlx->player->player_y + move_y);
 map_grid_x = (new_x / TILE_SIZE);
 map_grid_y = (new_y / TILE_SIZE);
 if (mlx->dt->map[map_grid_y][map_grid_x] != '1' && \
 (mlx->dt->map[map_grid_y][mlx->player->player_x / TILE_SIZE] != '1' && \
 mlx->dt->map[mlx->player->player_y / TILE_SIZE][map_grid_x] != '1'))
 {
  mlx->player->player_x = new_x;
  mlx->player->player_y = new_y;
 }
}

void hook(t_mlx *mlx, double move_x, double move_y)
{
 if (mlx->player->rot == 1)
  rotate_player(mlx, 1);
 if (mlx->player->rot == -1)
  rotate_player(mlx, 0);
 if (mlx->player->l_r == 1)
 {
  move_x = -sin(mlx->player->angle) * PLAYER_SPEED;
  move_y = cos(mlx->player->angle) * PLAYER_SPEED;
 }
 if (mlx->player->l_r == -1)
 {
  move_x = sin(mlx->player->angle) * PLAYER_SPEED;
  move_y = -cos(mlx->player->angle) * PLAYER_SPEED;
 }
 if (mlx->player->u_d == 1)
 {
  move_x = cos(mlx->player->angle) * PLAYER_SPEED;
  move_y = sin(mlx->player->angle) * PLAYER_SPEED;
 }
 if (mlx->player->u_d == -1)
 {
  move_x = -cos(mlx->player->angle) * PLAYER_SPEED;
  move_y = -sin(mlx->player->angle) * PLAYER_SPEED;
 }
 move_player(mlx, move_x, move_y);
}


void put_pixel_accordingly(t_mlx *mlx, int x, int y, int color)
{
 if (x < 0)
  return ;
 else if (x >= S_W)
  return ;
 if (y < 0)
  return ;
 else if (y >= S_H)
  return ;
 mlx_put_pixel(mlx->img, x, y, color);
}

float fix_angles(float angle)
{
 if (angle < 0)
  angle += (2 * M_PI);
 if (angle > (2 * M_PI))
  angle -= (2 * M_PI);
 return (angle);
}

void draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix)
{
 int  i;
 int  c;

 i = b_pix;
 while (i < S_H)
  put_pixel_accordingly(mlx, ray, i++, 0xB99470FF);
 i = 0;
 while (i < t_pix)
  put_pixel_accordingly(mlx, ray, i++, 0x89CFF3FF);
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

void draw_wall(t_mlx *mlx, int ray, int t_pix, int b_pix)
{
 int color;

 color = get_color(mlx, mlx->ray->f);
 while (t_pix < b_pix)
  put_pixel_accordingly(mlx, ray, t_pix++, color);
}

void render_wall(t_mlx *mlx, int ray)
{
 double wall_h;
 double b_pix;
 double t_pix;

 mlx->ray->dist *= cos(fix_angles(mlx->ray->r_angle - mlx->player->angle));
 wall_h = (TILE_SIZE / mlx->ray->dist) * ((S_W / 2) / tan(mlx->player->fov / 2));
 b_pix = (S_H / 2) + (wall_h / 2);
 t_pix = (S_H / 2) - (wall_h / 2);
 if (b_pix > S_H)
  b_pix = S_H;
 if (t_pix < 0)
  t_pix = 0;
 draw_wall(mlx, ray, t_pix, b_pix);
 draw_floor_ceiling(mlx, ray, t_pix, b_pix);
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

int check_wall_hit(float x, float y, t_mlx *mlx)
{
 int  x_m;
 int  y_m;

 if (x < 0 || y < 0)
  return (0);
 x_m = floor (x / TILE_SIZE);
 y_m = floor (y / TILE_SIZE);
 if ((y_m >= mlx->dt->h_map || x_m >= mlx->dt->w_map))
  return (0);
 if (mlx->dt->map[y_m] && x_m <= (int)strlen(mlx->dt->map[y_m]))
  if (mlx->dt->map[y_m][x_m] == '1')
   return (0);
 return (1);
}

float get_horizontal_int(t_mlx *mlx, float angl)
{
 float h_x;
 float h_y;
 float x_step;
 float y_step;
 int  pixel;

 y_step = TILE_SIZE;
 x_step = TILE_SIZE / tan(angl);
 h_y = floor(mlx->player->player_y / TILE_SIZE) * TILE_SIZE;
 pixel = check_intersection(angl, &h_y, &y_step, 1);
 h_x = mlx->player->player_x + (h_y - mlx->player->player_y) / tan(angl);
 if ((check_circle(angl, 'y') && x_step > 0) || (!check_circle(angl, 'y') && x_step < 0))
  x_step *= -1;
 while (check_wall_hit(h_x, h_y - pixel, mlx))
 {
  h_x += x_step;
  h_y += y_step;
 }
 return (sqrt(pow(h_x - mlx->player->player_x, 2) + pow(h_y - mlx->player->player_y, 2)));
}

float get_vertical_int(t_mlx *mlx, float angl)
{
 float v_x;
 float v_y;
 float x_step;
 float y_step;
 int  pixel;

 x_step = TILE_SIZE; 
 y_step = TILE_SIZE * tan(angl);
 v_x = floor(mlx->player->player_x / TILE_SIZE) * TILE_SIZE;
 pixel = check_intersection(angl, &v_x, &x_step, 0);
 v_y = mlx->player->player_y + (v_x - mlx->player->player_x) * tan(angl);
 if ((check_circle(angl, 'x') && y_step < 0) || (!check_circle(angl, 'x') && y_step > 0))
  y_step *= -1;
 while (check_wall_hit(v_x - pixel, v_y, mlx))
 {
  v_x += x_step;
  v_y += y_step;
 }
 return (sqrt(pow(v_x - mlx->player->player_x, 2) + pow(v_y - mlx->player->player_y, 2)));
}

void raycast(t_mlx *mlx)
{
 double h_inter;
 double v_inter;
 int  ray;

 ray = 0;
 mlx->ray->r_angle = mlx->player->angle - (mlx->player->fov / 2);
 while (ray < S_W)
 {
  mlx->ray->f = 0;
  h_inter = get_horizontal_int(mlx, fix_angles(mlx->ray->r_angle));
  v_inter = get_vertical_int(mlx, fix_angles(mlx->ray->r_angle));
  if (v_inter <= h_inter)
   mlx->ray->dist = v_inter;
  else
  {
   mlx->ray->dist = h_inter;
   mlx->ray->f = 1;
  }
  render_wall(mlx, ray);
  ray++;
  mlx->ray->r_angle += (mlx->player->fov / S_W);
 }
}


void game_loop(void *ml)
{
 t_mlx *mlx;

 mlx = ml;
 mlx_delete_image(mlx->mlx_p, mlx->img);
 mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H);
 hook(mlx, 0, 0);
 raycast(mlx);
 mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
}

void init_the_player(t_mlx mlx)
{
 mlx.player->player_x = mlx.dt->p_x * TILE_SIZE + TILE_SIZE / 2;
 mlx.player->player_y = mlx.dt->p_y * TILE_SIZE + TILE_SIZE / 2;
 mlx.player->fov = (FOV * M_PI) / 180;
 mlx.player->angle = M_PI;

}

void start_the_game(t_map *dt)
{
 t_mlx mlx;

 mlx.dt = dt;
 mlx.player = calloc(1, sizeof(t_player));
 mlx.ray = calloc(1, sizeof(t_ray));
 mlx.mlx_p = mlx_init(S_W, S_H, "Cub3D", 0);
 init_the_player(mlx);
 mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx);
 mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx);
 mlx_loop(mlx.mlx_p);
 ft_exit(&mlx);
}

// t_map *init_argumet(t_map *map)
// {
//  t_map *dt = calloc(1, sizeof(t_map));
//  dt->map = calloc(10, sizeof(char *));
// 	dt->map = map->map;
//  dt->p_y = 3;
//  dt->p_x = 14;
//  dt->w_map = 25;
//  dt->h_map = 9;
//  return (dt);
// }
void v()
{
 system("leaks cub3D");
}
// int main()
// {
//  t_map *data;
//  atexit(v);
//  data = init_argumet();
//  start_the_game(data);
//  return 0;
// }
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