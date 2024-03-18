#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "malloc.h"
# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define S_W 1920
# define S_H 1080
# define TILE_SIZE 15
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

typedef struct s_player
{
	int				player_x;
	int				player_y;
	double			angle;
	float			fov;
	int				rot;
	int				l_r;
	int				u_d;
}					t_player;

typedef struct s_ray
{
	double			r_angle;
	double			dist;
	double			horiz_x;
	double			horiz_y;
	double			vert_x;
	double			vert_y;
	int				f;
	int				index;
}					t_ray;
typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	t_ray			*ray;

	t_player		*player;
}					t_mlx;
typedef struct s_texture
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}					t_texture;

typedef struct s_map
{
	int				h;
	int				w;
	size_t			len_map;
	t_texture		*texture;
	char			**map;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*s;
	char			*f;
	char			*c;
	int				p_x;
	int				p_y;
	int				w_map;
	int				h_map;
	t_mlx			mlx;
}					t_map;

// main.c
int					check_sec_arg(char *argv);
void				game_loop(void *ml);
void				start_game(t_map *data);
int					main(int argc, char **argv);

// gen_utils.c
void				ft_exit(t_map *data, char *sms);
void				free_split(char **arr);
// void				ft_exit(t_map *data);
// void				init_the_player(t_map *data);
void				put_pixel_accordingly(t_map *data, int x, int y,
						unsigned int color);
int					check_circle(float angle, char c);

// movements.c
void				ft_initkeys(mlx_key_data_t keydata, t_map *data);
void				mlx_key(mlx_key_data_t keydata, void *ml);
void				rotate_player(t_map *data, int i);
void				move_player(t_map *data, double move_x, double move_y);
void				hook(t_map *data, double move_x, double move_y);

// parcing_utils1.c
t_map				*manage_data(char *s);
// char				*get_next_line(int fd);
t_map				*get_map_data(char *s);
// t_map   *get_map_data(char *s);

// parcing_utils2.c
void				manage_directions(char *s, t_map *data);
void				manage_sfc(char *s, t_map *data);
int					get_x(char *s);
void				getmapcord(t_map *data);

// parcing.c
int					checkh(char *s);
int					checkfirstline(char **s);
int					checklastline(char **s);
int					checkmap(t_map *data);
// int					checkmap(char **s);

// raycasting.c
int					check_intersection(float angle, float *inter, float *step,
						int is_horizon);
int					check_wall_hit(float x, float y, t_map *dt);
float				get_horizontal_int(t_map *data, float angl);
float				get_vertical_int(t_map *data, float angl);
void				raycast(t_map *data);

// rendering.c
float				fix_angles(float angle);
int32_t				ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void				draw_floor_ceiling(t_map *data, int ray, int t_pix,
						int b_pix);
int					get_color(t_mlx *mlx, int f);
void				render_wall(t_map *data, int ray);

// textures.c
int					get_texture_data(t_map *data);
mlx_texture_t		*get_texture(t_map *data, int flag);
double				get_x_o(mlx_texture_t *texture, t_map *data);
unsigned int		reverse_bytes(int c);
void				draw_wall(t_map *data, int t_pix, int b_pix,
						double wall_h);

#endif /* GAME_H */
