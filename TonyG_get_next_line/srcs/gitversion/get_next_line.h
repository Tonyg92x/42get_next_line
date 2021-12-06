/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:19:19 by aguay             #+#    #+#             */
/*   Updated: 2021/12/02 14:20:15 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NET_LINE_H
# define GET_NET_LINE_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_putstr_getnext_fd(char *s, int fd);
bool	ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*buff_set(char *line, char *buffer);
char	*line_fix(char *line);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_print_buf(char *buffer);
#endif
