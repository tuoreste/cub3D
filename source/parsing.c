/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:48:34 by aguediri          #+#    #+#             */
/*   Updated: 2024/02/15 16:48:09 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_exit(t_data *data, char *str)
{
	mlx_close_window(data->mlx);
	mlx_strerror(mlx_errno);
	write(2, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;

	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf,
				BUFFER_SIZE)) > 0)
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
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
}
t_map	*manage_data(char *s)
{
	int		i;
	t_map	*data;
	char	**t;
	char	**t1;
	char	*map;

	data = (t_map *)malloc(sizeof(t_map));
	map = "";
	i = 0;
	t = ft_split(s, '\n');
	while (t[i])
	{
		if (ft_strnstr(t[i], "NO", 2) || ft_strnstr(t[i], "SO", 2)
			|| ft_strnstr(t[i], "WE", 2) || ft_strnstr(t[i], "EA", 2))
			manage_directions(t[i], data);
		else if (ft_strnstr(t[i], "S", 1) || ft_strnstr(t[i], "C", 1)
			|| ft_strnstr(t[i], "F", 1))
			manage_sfc(t[i], data);
		else if (ft_strnstr(t[i], "S", 1))
		{
			t1 = ft_split(t[i], ' ');
			data->h = ft_atoi(t1[1]);
			data->w = ft_atoi(t1[2]);
		}
		else if (ft_strlen(ft_strtrim(t[i], " \t012NSWE")) == 0)
		{
			map = ft_strjoin(map, t[i]);
			map = ft_strjoin(map, "\n");
		}
		i++;
	}
	data->map = ft_split(map, '\n');
	return (data);
}
t_map	*get_map_data(char *s)
{
	int		fd;
	char	*line;
	char	*str;
	t_map	*data;

	fd = open(s, O_RDONLY);
	str = "";
	data = NULL;
	if (!fd)
	{
		perror("Error opening file");
		return (NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		str = ft_strjoin(str, line);
		free(line);
	}
	close(fd);
	// printf("%s", str);
	data = manage_data(str);
	return (data);
}
int	checkfirstline(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(ft_strtrim(s[0], "1 \t")))
	{
		return (0);
	}
	while (s[0][j])
	{
		if (s[0][j] == ' ' || s[0][j] == '\t')
		{
			while (s[i][j] == ' ' || s[i][j] == '\t')
			{
				i++;
			}
			if (s[i][j] == '0')
				return (0);
			i = 0;
		}
		j++;
	}
	return (1);
}
int	checklastline(char **s)
{
	int	i;
	int	j;
	int	last_line_index;

	j = 0;
	last_line_index = 0;
	while (s[last_line_index + 1] != NULL)
		last_line_index++;
	i = last_line_index;

	if (ft_strlen(ft_strtrim(s[last_line_index], "1 \t")))
		return (0);
	while (s[last_line_index][j])
	{
		if (s[last_line_index][j] == ' ' || s[last_line_index][j] == '\t')
		{
			while (s[i][j] == ' ' || s[i][j] == '\t')
				i--;
			if (s[i][j] == '0')
				return(0);
			i = last_line_index;
		}
		j++;
	}
	return (1);
}
int checkh(char *s)
{
	int i = 1;
	while(s[i + 1])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			if (s[i - 1] == '0' || s[i + 1] == '0')
				return(0);
		}
		i++;
	}
	return(1);
}
int	checkmap(char **s)
{
	int	i;
	int	r;
	int	u;

	i = 0;
	r = 1;
	u = 0;
	if (!ft_strlen(s[0]))
		return (0);
	r = checkfirstline(s);
	if (r)
		r = checklastline(s); 
	while (s[i])
	{
		printf("%s\n",s[i]);
		if (ft_strlen(ft_strtrim(s[i], "01 \tNSWE")) != ft_strlen(ft_strtrim(s[i], "01 \t")))
			u++;
		if (ft_strlen(ft_strtrim(s[i], "01 \tNSWE")) || !checkh(s[i]))
			return (0);
		char *s1 = ft_strtrim(s[i], " \t");
		if (s1[ft_strlen(s1) - 1] != '1' || s1[0] != '1')
			return(0);
		i++;
	}
	if (ft_strlen(ft_strtrim(s[i - 1], " 1\t")))
		return (0);
	if (u != 1)
		return (0);
	return (r);
}
