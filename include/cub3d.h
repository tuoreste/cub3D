#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "fcntl.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ttslist.h"
# include "ft_maths.h"
# include "ft_simplesdl.h"

// # define MAP_W 24
// # define MAP_H 24
// # define SCREEN_W 640
// # define SCREEN_H 480
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 42
// # endif

// typedef struct s_player
// {
// 	double		x;
// 	double		y;
// 	double		dir_x;
// 	double		dir_y;
// 	double		pl_x;
// 	double		pl_y;
// 	double		rotations;
// 	double		dest_x;
// 	double		dest_y;
// 	double		tot_rotations;
// }				t_player;

// typedef struct s_ray
// {
// 	double		x_dir;
// 	double		y_dir;
// 	double		x_plane;
// 	double		y_plane;
// 	double		side_dist_x;
// 	double		side_dist_y;
// 	double		delta_dist_x;
// 	double		delta_dist_y;
// 	double		camera_x;
// 	double		ray_dir_x;
// 	double		ray_dir_y;
// }				t_ray;

// typedef struct s_img
// {
// 	void		*img;
// 	int			width;
// 	int			height;
// 	int			endian;
// 	int			bits_per_pixel;
// 	int			line_len;
// }				t_img;

// typedef struct s_data
// {
// 	char		*addr;
// 	void		*mlx;
// 	void		*win_mlx;
// 	float		x0;
// 	float		x1;
// 	float		y0;
// 	float		y1;
// 	void		*px_img;
// 	t_img		**img;
// 	t_ray		*rays;
// 	t_player	*player;
// }				t_data;

// typedef struct s_map
// {
// 	int			h;
// 	int			w;
// 	size_t		len_map;
// 	char		**map;
// 	char		*north;
// 	char		*south;
// 	char		*east;
// 	char		*west;
// 	char		*s;
// 	char		*f;
// 	char		*c;
// }				t_map;

// t_map			*get_map_data(char *s);

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define MAP_W 10
# define MAP_H 10
# define GRID_SIZE 50
# define MAX_VIEW_DISTANCE 10000
# define WALL_HEIGHT_SCALE 50.0

extern	t_sdl_image *g_image;
extern	t_sdl_env	g_sdl_env;
extern	int			g_cub_map[MAP_W][MAP_H];

typedef	struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

typedef struct	s_dda
{
	t_vector	current_pos;
	t_point		pos_on_grid;
	int			nextX;
	int			nextY;
	t_vector	d;
	double		final_d;
	t_point		sign;
	t_intersect	intersection;
}				t_dda;


typedef	struct s_intersect
{
	t_vector		pos;
	t_point			grid_pos;
	int				grid_value;
	double			distance;
	unsigned char	does_intersect;
}				t_intersect;

typedef	struct s_camera
{
	double			projection_plane_distance;
	double			projection_plane_size;
	t_ray			ray;
	t_intersect		intersection;
}					t_camera;

typedef	struct s_cub_env
{
	t_camera	camera;
}				t_cub_env;

extern t_cub_env	g_cub_env;

int		init(void);
int		raycast_main(void);
void	debug_draw_camera();

#endif
