/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:18:19 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/18 17:06:00 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	v(void)
// {
// 	system("leaks cub3d");
// }

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_exit(t_map *data, char *sms)
{
	int	i;

	i = 0;
	// if (data->c)
		free(data->c);
	// if (data->s)
		free(data->s);
	// if (data->f)
		free(data->f);
	// if (data->north)
		free(data->north);
	// if (data->south)
		free(data->south);
	// if (data->east)
		free(data->east);
	// if (data->west)
		free(data->west);
	// if (data->texture->ea)
		free(data->texture->ea);
	// if (!data->texture->no)
		free(data->texture->no);
	// if (data->texture->we)
		free(data->texture->we);
	// if (data->texture->so)
		free(data->texture->so);
	// if (data->texture)
		free(data->texture);
	// if (data->mlx.img)
		mlx_delete_image(data->mlx.mlx_p, data->mlx.img);
	// if (data->mlx.mlx_p)
		mlx_close_window(data->mlx.mlx_p);
	mlx_terminate(data->mlx.mlx_p);
	//  free(mlx->dt);
	// if (data->mlx.player)
		free(data->mlx.player);
	// if (data->mlx.ray)
		free(data->mlx.ray);
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	free(data);
	printf("%s\n", sms);
	// system("leaks cub3d");
	// atexit(v);
	// show_alloc_mem_ex();
	// print_leaks();
	exit(0);
}

void	put_pixel_accordingly(t_map *data, int x, int y, unsigned int color)
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

int	check_circle(float angle, char c)
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
