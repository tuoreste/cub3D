/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:20:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/11 21:48:20 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2 || ft_strnstr(argv[1], ".cub", 4))
		printf("error");
	map = get_map_data(argv[1]);
	if (!checkmap(map->map))
		printf("not valid");
	else
		printf("valid af");
}
