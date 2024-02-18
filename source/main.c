/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:35:00 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/18 16:23:38 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_gen(char *err)
{
	while (*err)
		write (1, err++, 1);
	return (1);
}

int	free_all()
{
	t_game *game;

	free(game->map);
	printf("Hiiiiiiiiiiiiiiiii\n");
	free(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)calloc(sizeof(t_game), 1);
	game->map = (t_maps *)calloc(sizeof(t_maps), 1);
	if (argc != 2)
		return (error_gen("Error: wrong number of args\n"));
	parser(argv[1], game->map); //give argv[1] to struct map
	launch_game(game); //make necessary game initializations
	build_game(game); //rest of constructions called within build
	// if (!free_all())
	// 	return (EXIT_FAILURE); //free memo
	return (EXIT_SUCCESS);
}
	