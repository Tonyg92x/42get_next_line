/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:57 by aguay             #+#    #+#             */
/*   Updated: 2021/12/01 14:18:58 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

bool	ft_nl(char *s)
{
	int count;

	count = 0;
	while (s[count])
	{
		if (s[count++] == '\n')
			return (false);
	}
	return (true);
}

void	ft_putstr_getnext_fd(char *s, int fd)
{
	int	count;

	if (!s)
		return ;
	count = 0;
	while (s[count] && s[count] != '\n')
		write(fd, &s[count++], 1);
	if (s[count] == '\n')
		write(fd, "\n", 1);
}

void	ft_buffersaver(char *line, char *buffer)
{
	int		len;
	int		count;
	int		buffer_count;

	buffer_count = 0;
	count = 0;
	len = ft_strlen(line) - 1;
	while (line[count] != '\0' && count != len)
		count ++;
	if (count == len)
	{
		buffer[0] = '\0';
		return;
	}
	while (line[count])
		buffer[buffer_count++] = line[count++];
}
