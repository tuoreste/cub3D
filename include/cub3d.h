#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WINDOW_WIDTH 840
# define WINDOW_HEIGHT 720
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define TILE_SIZE 30
# define MAX_LINE_LENGTH 100
# define NUM_RAYS WINDOW_WIDTH
# define RAY_LENGTH 100.0
# define MAP_ROWS 10
# define MAP_COLS 10
// Field of View angle in radians
# define FOV_ANGLE (60 * (M_PI / 180))

typedef struct s_parse
{
	int					fd;
	char				*line;
	size_t				len;
	int					map_start;
	int					line_number;
	char				*token;
}						t_parse;

typedef struct s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct s_camera
{
}						t_camera;

typedef struct s_ray
{
	t_point				origin;
	double				angle;
}						t_ray;

typedef struct s_intersection
{
	double				distance;
	double				distance_to_wall;
	t_point				crossed;
}						t_intersection;

typedef struct s_raycast_result
{
	double				distance;
	int					texture_id;
	int					strip;
}						t_raycast_result;

typedef struct s_keys
{
	int					up;
	int					down;
	int					left;
	int					right;
}						t_keys;

typedef struct s_player
{
	double				x;
	double				y;
	double				direction;
	double				rotation_angle;
	double				move_speed;
	double				rotation_speed;
	double				dist_to_projection_plane;

}						t_player;

typedef struct s_maze
{
	char				map[MAP_HEIGHT][MAP_WIDTH + 1];
}						t_maze;

typedef struct s_texture
{
	char				*path;
	void				*no_tex;
	void				*so_tex;
	void				*ea_tex;
	void				*we_tex;
}						t_texture;

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct s_settings
{
	t_texture			*no_tex;
	t_texture			*so_tex;
	t_texture			*we_tex;
	t_texture			*ea_tex;
	t_color				floor_color;
	t_color				ceiling_color;
}						t_settings;

typedef struct s_game
{
	void				*mlx;
	void				*img;
	void				*addr;
	void				*win;
	int					size;
	int					width;
	int					height;
	char				**map;
	int					line_length;
	long long int		bits_per_pixel;
	t_ray				ray;
	t_parse				parse;
	t_player			player;
	t_maze				maze;
	t_settings			settings;
	t_texture			textures;
	t_keys				keys;
	t_intersection		intersect;
	t_raycast_result	raycast;
}						t_game;

void					error_return(char *str);
void					error_format(char *str, int line_n);
void					ft_check_format(t_game *game, char *c);
void					read_scene_file(char *file_path, t_game *game);
int						main(void);

// Function prototypes
// void					read_scene_file(char *file_path, t_game *game);
// void					setup_game(t_game *game);
// void					update(t_game *game);
// void					render(t_game *game);
// void					draw_rectangle(t_game *game, int x, int y);
// void					draw_player(t_game *game);
// void					draw_maze(t_game *game);
// void					cast_rays(t_game *game);
// void					draw_line(t_game *game, int x1, int y1, int x2, int y2,
// 							int color);
// double					normalize_angle(double angle);
// void					move_player(t_game *game, double delta_x,
// 							double delta_y);
// void					rotate_player(t_game *game, double rotation);
// void					move_player_forward(t_game *game);
// void					move_player_backward(t_game *game);
// void					rotate_player_left(t_game *game);
// void					rotate_player_right(t_game *game);
// void					draw_wall_strip(t_game *game, int strip,
// 							int wall_height);

#endif
