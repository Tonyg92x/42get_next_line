/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:19:19 by aguay             #+#    #+#             */
/*   Updated: 2021/12/01 14:19:01 by aguay            ###   ########.fr       */
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

int		*ft_strchr(char *s, int c);
void	ft_putstr_getnext_fd(char *s, int fd);
bool	ft_nl(char *s);
size_t	ft_strlen(const char *str);
void	ft_buffersaver(char *line, char *buffer);
char	*get_next_line(int fd);
#endif
