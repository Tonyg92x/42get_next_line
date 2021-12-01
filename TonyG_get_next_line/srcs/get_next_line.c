/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2021/12/01 14:45:43 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	size_t		len;
	int			count;
	char		*line;
	static char	buffer[BUFFER_SIZE];
	bool		run;

	run = true;
	count = 0;
	line = malloc(BUFFER_SIZE + 1);
	while (run)
	{
		len = 0;
		if (*buffer == '\0')
			len = read(fd, line, BUFFER_SIZE);
		else
		{
			while (buffer[count] && count < BUFFER_SIZE)
			{
				line[count] = buffer[count];
				count++;
			}
		}
		line[BUFFER_SIZE] = '\0';
		ft_putstr_getnext_fd(line, 1);
		run = ft_nl(line);
		if (!run)
			ft_buffersaver(line, buffer);
	}
	if (len == 0)
		return (NULL);
	return (line);
}

