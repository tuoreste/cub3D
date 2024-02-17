/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:35:00 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/17 13:23:43 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_gen(void);

void	free_all(void)
{
	t_game *game;
	t_game *map;

	free(map);
	free(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_maps	*map;

	game = (t_game *)calloc(sizeof(t_game), 1);
	map = (t_maps *)calloc(sizeof(t_maps), 1);
	if (argc != 2)
		return (error_gen());
	parser(argv[1], map); //give argv[1] to struct map
	game_init(game); //make necessary game initializations
	build_game(game); //rest of constructions called within build
	free_all(); //free memo
	return (EXIT_SUCCESS);
}
	