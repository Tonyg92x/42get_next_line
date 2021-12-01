/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:26:26 by aguay             #+#    #+#             */
/*   Updated: 2021/12/01 14:49:42 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
	}
	free(line);
	if (close(fd) == -1)
	{
		printf("close() error");
		return (1);
	}
	return (0);
}

