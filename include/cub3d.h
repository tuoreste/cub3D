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
# define PI 3.1415926
// Field of View angle in radians
# define FOV_ANGLE ((60 * M_PI) / 180)
# define ROT 0.174533 // 10 degrees in radians

typedef struct s_vector {
	double x;
	double y;
} t_vector;

typedef struct s_point
{
	double				x;
	double				y;
	int					mapx;
	int					mapy;
}						t_point;

typedef struct s_image
{
	int					x;
	int					y;
	void				*img;
	float				angle;
	unsigned int		*rotated_data;
	int					relative_x;
	int					relative_y;
	int					new_x;
	int					new_y;
	int					center_x;
	int					center_y;
	int					img_width;
	int					img_height;
	float				radians;
	float				player_orient;
}						t_image;

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
	keys_t				*key;
}						t_keys;

typedef struct s_player
{
	struct mlx_image	*img;
	int				x;
	int				y;
	// double				dir_x;
	// double				dir_y;
	t_vector			pos;
	t_vector			dir;
	double				delta_x;
	double				delta_y;
	double				p_angle;
	double				direction;
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


typedef struct s_parse
{
	int					fd;
	char				*line;
	size_t				len;
	int					map_start;
	int					line_number;
	char				*token;
}						t_parse;

typedef struct s_game
{
	mlx_t				*mlx;
	void				*img;
	void				*addr;
	void				*win;
	int					size;
	int					i;
	int					width;
	int					height;
	char				**map;
	int					line_length;
	long long int		bits_per_pixel;
	float				pa;
	float				pdx;
	float				pdy;
	t_point				pt;
	t_vector			*vec;
	t_image				*image;
	t_ray				ray;
	t_parse				parse;
	t_player			*player;
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

// #ifndef CUB3D_H
// # define CUB3D_H

// # include "MLX42.h"
// # include "get_next_line.h"
// # include "libft.h"
// # include <fcntl.h>
// # include <math.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <string.h>
// # include <unistd.h>

// typedef struct t_vector {
//     double x;
//     double y;
//     double dir;
// } t_vector;
// // Structure definitions

// typedef struct t_ray {
//     t_vector origin;       // Ray origin
//     t_vector dir;          // Ray direction
//     double wall_dist;      // Distance to hit wall
//     int wall_hit;      // Whether a wall was hit
// 	double dir_x;
// 	double dir_y;
// 	int hit_x;
// 	double camera_plane_x;
// 	double camera_plane_y;
// 	double max_distance;
//     // ... (Add other ray-related data members as needed)
// } t_ray;

// typedef struct t_texture {
//     // Data members representing your texture data format
//     unsigned char *data; // Assuming raw pixel data
//     int width;
//     int height;
// } t_texture;

// typedef struct s_image
// {
// 	int					x;
// 	int					y;
// 	void				*imag;
// 	float				angle;
// 	unsigned int		*rotated_data;
// 	int					relative_x;
// 	int					relative_y;
// 	int					new_x;
// 	int					new_y;
// 	int					center_x;
// 	int					center_y;
// 	int					img_width;
// 	int					img_height;
// 	float				radians;
// 	float				player_orient;
// 	mlx_instance_t		*instances;
// }						t_image;

// typedef struct t_player {
// 	void	*imag;
//     t_image *img;             // Player image
// 	t_vector			pos;

//     // ... (Add other player-related data members as needed)
// } t_player;

// typedef struct s_point
// {
// 	double				x;
// 	double				y;
// 	int					mapx;
// 	int					mapy;
// }						t_point;

// typedef struct t_game {
//     void *img;          // Image for rendering
//     void *mlx;          // MLX pointer
//     t_vector *player_pos; // Player position
//     t_player *player;    // Player struct pointer
// 	t_point	*pt;
// 	t_texture		floor_texture;
// 	t_texture		ceiling_texture;
// 	int		ceiling_height;
//     // ... (Add other game-related data members as needed)
// } t_game;

// // Function prototypes for texture loading/handling (if needed)
// int load_texture(const char *file_path, t_texture *texture);
// void free_texture(t_texture *texture);

// // Function prototypes
// void draw_map2d(t_game *game);
// void draw_player(void *param);
// void buttons(void *param);

// // Additional function prototypes for texture access (to be filled in)
// int get_wall_texture_color(int wall_hit, t_texture wall_texture, double hit_x);
// int get_ceiling_texture_color(int x, int y, t_texture *ceiling_texture);
// int get_floor_texture_color(int x, int y, t_texture *floor_texture);

// # define WINDOW_WIDTH 840
// # define WINDOW_HEIGHT 720
// # define MAP_WIDTH 24
// # define MAP_HEIGHT 24
// # define TILE_SIZE 30
// # define MAX_LINE_LENGTH 100
// # define NUM_RAYS WINDOW_WIDTH
// # define RAY_LENGTH 100.0
// # define MAP_ROWS 10
// # define MAP_COLS 10
// # define PI 3.1415926
// // Field of View angle in radians
// # define FOV_ANGLE ((60 * M_PI) / 180)
// # define ROT 0.174533 // 10 degrees in radians
// #define FLOOR_SCALE 0.1
// #define CEILING_SCALE 0.8

// // Include other header files as needed

// #endif /* GAME_H */
