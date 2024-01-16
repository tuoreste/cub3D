/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:39:04 by otuyishi          #+#    #+#             */
/*   Updated: 2023/05/27 23:53:37 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c_s;
	size_t	count1;
	size_t	count2;

	count1 = 0;
	count2 = 0;
	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	c_s = (char *)malloc(sizeof(*s) * (len + 1));
	if (!c_s)
		return (NULL);
	while (s[count1] && count2 < len)
	{
		if (count1 >= start)
		{
			c_s[count2] = s[count1];
			count2++;
		}
		count1++;
	}
	c_s[count2] = 0;
	return (c_s);
}

char	*get_txt(int fd, char **line)
{
	char	*buffer;
	int		byte_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(*line), NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read == -1)
		return (free(buffer), free(*line), NULL);
	buffer[byte_read] = '\0';
	while (byte_read > 0)
	{
		*line = ft_strjoin(*line, buffer);
		if (*line && ft_strchr(*line, '\n'))
			break ;
		if (*line == NULL)
			return (free(buffer), NULL);
		free(buffer);
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (*line);
		buffer[byte_read] = '\0';
	}
	return (free(buffer), buffer = NULL, *line);
}

char	*get_updated(char *line)
{
	char	*buffer;
	int		start;
	int		move;

	start = 0;
	move = 0;
	if (line == NULL)
		return (NULL);
	while (line[start] && line[start] != '\n')
		start++;
	if (!line[start])
		return (free(line), NULL);
	start++;
	buffer = malloc(sizeof(char) * ((ft_strlen(line + start)) + 1));
	if (buffer == NULL)
		return (free(line), NULL);
	while (line[start + move])
	{
		buffer[move] = line[start + move];
		move++;
	}
	buffer[move] = '\0';
	if (buffer[0] == 0)
		return (free(line), free(buffer), NULL);
	return (free(line), buffer);
}

char	*get_rslt(char *line)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	res = ft_substr(line, 0, (i + 1));
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*line[BUFFER_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = get_txt(fd, &line[fd]);
	if (line[fd] == NULL)
		return (NULL);
	res = get_rslt(line[fd]);
	line[fd] = get_updated(line[fd]);
	return (res);
}
