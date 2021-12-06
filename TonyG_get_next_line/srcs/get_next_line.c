/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2021/12/02 15:07:40 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int		len;
	char		*ptr;

	ptr = buffer;
	len = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	ptr = ft_print(buffer);
	write(1, "\n", 1);
	if (len == 0)
		return (NULL);
	return (buffer);
}

char	*ft_print(char	*buffer)
{
	int	count;

	while (buffer[0] != '\n' && buffer[0] != '\0')
	{
		count = 0;
		write(1, &buffer[0], 1);
		while (buffer[count] != '\0')
		{
			buffer[count] = buffer[count + 1];
			count++;
		}
	}
	return (buffer);
}

