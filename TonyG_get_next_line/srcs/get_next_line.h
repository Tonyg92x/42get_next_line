/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:19:19 by aguay             #+#    #+#             */
/*   Updated: 2021/12/08 13:01:06 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NET_LINE_H
# define GET_NET_LINE_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_get(char  *buffer, int *len, int fd, char *retour,int *count_ret);
bool	ft_protection(char **buffer, char **retour, int *count_ret);
#endif
