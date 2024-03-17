/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:18:19 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/17 11:31:41 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	free(data->c);
	free(data->f);
	free(data->s);
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
	if (data->texture->ea)
		free(data->texture->ea);
	if (!data->texture->no)
		free(data->texture->no);
	if (data->texture->we)
		free(data->texture->we);
	if (data->texture->so)
		free(data->texture->so);
	if (data->texture)
		free(data->texture);
	mlx_delete_image(data->mlx.mlx_p, data->mlx.img);
	mlx_close_window(data->mlx.mlx_p);
	mlx_terminate(data->mlx.mlx_p);
	//  free(mlx->dt);
	free(data->mlx.player);
	free(data->mlx.ray);
	while (data->map[i])
	{
		printf("%p\n", data->map[i]);
		free(data->map[i++]);
	}
	free(data->map);
	free(data);
	printf("%s\n", sms);
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
