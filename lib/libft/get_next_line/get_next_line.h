/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:48:16 by otuyishi          #+#    #+#             */
/*   Updated: 2024/02/07 12:29:50 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft.h"

char	*get_next_line(int fd);
char	*get_rslt(char *line);
char	*get_updated(char *line);
char	*get_txt(int fd, char **line);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//void	*ft_strdup(const char *s1);
//void	*ft_memcpy(void *dst, const void *src, size_t n);
// char	*ft_strchr(const char *str, int c);
// char	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlen(const char *str);

#endif
