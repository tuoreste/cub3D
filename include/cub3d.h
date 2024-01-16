#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "MLX42.h"
# include "libft.h"

# define MAP_W 24
# define MAP_H 24
# define SCREEN_W 640
# define SCREEN_H 480

typedef struct s_ray
{
	double	x_dir;
	double	y_dir;
	double	x_plane;
	double	y_plane;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_ray;

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*win_mlx;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	float	x0;
	float	x1;
	float	y0;
	float	y1;
}	t_data;

typedef struct s_map
{
	size_t	len_map;
	char	**map;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
}	t_map;

#endif
