#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "cub3d.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MAX_LINE_LENGTH 100
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define TILE_SIZE 64
# define NUM_RAYS WINDOW_WIDTH
# define RAY_LENGTH 100.0
# define MAP_ROWS 10
# define MAP_COLS 10
// Field of View angle in radians
# define FOV_ANGLE (60 * (M_PI / 180))

typedef struct s_ray
{
	double			angle;
	double			distance;
}					t_ray;

typedef struct s_player
{
	double			x;
	double			y;
	double			direction;
	double			rotation_angle;
	double			move_speed;
	double			rotation_speed;
}					t_player;

typedef struct s_maze
{
	char			map[MAP_HEIGHT][MAP_WIDTH + 1];
}					t_maze;

typedef struct s_texture
{
	char			*path;
	void	*north_texture;
	void	*south_texture;
	void	*east_texture;
	void	*west_texture;
}					t_texture;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct s_settings
{
	t_texture		north_texture;
	t_texture		south_texture;
	t_texture		west_texture;
	t_texture		east_texture;
	t_color			floor_color;
	t_color			ceiling_color;
}					t_settings;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	t_player		player;
	t_maze			maze;
	t_settings		settings;
	t_texture		textures;
}					t_game;

// Function prototypes
void				read_scene_file(char *file_path, t_game *game);
void				setup_game(t_game *game);
void				update(t_game *game);
void				render(t_game *game);
void				draw_rectangle(t_game *game, int x, int y);
void				draw_player(t_game *game);
void				draw_maze(t_game *game);
void				cast_rays(t_game *game);
void				draw_line(t_game *game, int x1, int y1, int x2, int y2, int color);
double				normalize_angle(double angle);
void				move_player(t_game *game, double delta_x, double delta_y);
void				rotate_player(t_game *game, double rotation);

#endif
