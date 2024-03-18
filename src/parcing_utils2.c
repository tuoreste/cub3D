/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:03:14 by otuyishi          #+#    #+#             */
/*   Updated: 2024/03/18 15:13:29 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	manage_directions(char *s, t_map *data)
{
	char	**t;

	t = ft_split(s, ' ');
	if (t[0][0] == 'N')
		data->north = ft_strdup(t[1]);
	else if (t[0][0] == 'S')
		data->south = ft_strdup(t[1]);
	else if (t[0][0] == 'W')
		data->west = ft_strdup(t[1]);
	else if (t[0][0] == 'E')
		data->east = ft_strdup(t[1]);
	free_split(t);
}

void	manage_sfc(char *s, t_map *data)
{
	char	**t;

	t = ft_split(s, ' ');
	if (t[0][0] == 'F')
		data->f = ft_strdup(t[1]);
	else if (t[0][0] == 'S')
		data->s = ft_strdup(t[1]);
	else if (t[0][0] == 'C')
		data->c = ft_strdup(t[1]);
	free_split(t);
}

int get_x(char *s)
{
    int i = 0;
    while(s[i])
    {
        if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E')
            return(i);
        i++;
    }
    return(0);
}

void	getmapcord(t_map *data)
{
	int	i;
	char *s;

	i = 0;
    data->w_map = 0;
	while (data->map[i])
	{
        if ((int)ft_strlen(data->map[i]) > data->w_map)
            data->w_map = ft_strlen(data->map[i]);
		s = ft_strtrim(data->map[i], " \t01");
		if (ft_strlen(s))
		{
			data->p_y = i;
            data->p_x = get_x(data->map[i]);
		}
		free(s);
        i++;
	}
    data->h_map = i - 1;
}
