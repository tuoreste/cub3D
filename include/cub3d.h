#ifndef CUB3D_H
# define CUB3D_H

//=================start of defs=================

# include "MLX42.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WINDOW_HEIGHT 640
# define WINDOW_WIDTH 480
# define MOV_SPEED 0.1
# define ROT_SP 0.05
# define TILE 64

//=================end of defs===================
//=================start of structs=========

typedef struct s_render
{
	int			h_line;
	int			draw_strt;
	int			draw_end;
	double		ratio;
	int			pix_texture[2];
	double		pos_texture;
	short		dir_wall;
}				t_render;

typedef struct s_ray
{
	int				s;
	double			perp_wall_dist;
	double			cam_x;
	short			wall_dir;
	double			dir_ray[2];
	unsigned short	step[2];
	unsigned short	tile[2];
	short			wall_wards[2];
	unsigned short	dist_to_nxt_contour[2];
	unsigned short	portion_of_rem_tile[2];
}					t_ray;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_maps
{
	int				floor[2];
	int				etage;
	int				ceil[2];
	int				plafo;
	char			texture[4];
	char			**map;
	t_vector		vect[3];
	t_ray			ray;
	t_game			*game;
}	t_maps;

typedef struct s_game
{
	int 			color;
	int				hit;
	int				x_texture;
	int				y_texture;
	mlx_t			*mlx;
	int32_t			scrn_h;
	int32_t			scrn_w;
	mlx_image_t		*img;
	mlx_texture_t	*walls[4];
	t_maps			*map;
}	t_game;

//=================end of structs=========
//=================start of enums=================

enum e_keys
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	C = 4,
	F = 5
};

enum e_rgb
{
	R = 0,
	G = 1,
	B = 2
};

enum e_axis
{
	X = 0,
	Y = 1
};

enum e_vectors
{
	POS = 0,
	DIR = 1,
	CAM = 2
};

enum e_dimensions
{
	S_WIDTH = 1920,
	S_HEIGHT = 1080
};

//=================end of enums=============
//=================start of protos========

//------main.c-------|
int			main(int argc, char **argv);
int			error_gen(void);

//------cub3D.c-------|
void		maze(void *param);
void		build_game(t_game *game);
void		game_init(game);

//------parser.c------|
void		parser(char **argv, t_maps *map);

//------motion.c------|
void		move(void *param);
void		rotation(t_game *game);
void		camera(t_game *game);
void		direction(t_game *game);

//------decorate.c------|
void		select_color(t_game *game);
int			color_rgba(int r, int g, int b);
int			pull_color_texture(mlx_texture_t *texture, int x_texture, \
			int y_texture);

//------render.c------|
t_render	feed_info_to_render(t_maps *map, t_ray *ray);
void		initiate_rays(t_maps *map, t_ray *ray, int x);
void		compute_ray_steps(t_maps *map, t_ray *ray);


//------cast.c------|
void		draw_line_dda(t_maps *map, t_ray *ray, t_game *game);
void		reciprocate_dir_vec(t_maps *map, t_ray *ray, int x);


//=================end of protos==========

#endif /* GAME_H */
