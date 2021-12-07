/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2021/12/07 11:19:42 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			len;
	int			count_ret;
	char		*ptr;
	char		*retour;

	count_ret = 0;
	retour = malloc(10000);
	ptr = buffer;
	len = 1;
	if (buffer[0] != '\0')
		ptr = ft_print(buffer, &len, fd, retour, &count_ret);
	else
	{
		len = read(fd, buffer, BUFFER_SIZE);
		ptr = ft_print(buffer, &len, fd, retour, &count_ret);
	}
	if (len == 0)
	{
		free (retour);
		return (NULL);
	}
	return (retour);
}

char	*ft_print(char	*buffer, int *len, int fd, char *retour,int *count_ret)
{
	int	count;

	while (buffer[0] != '\n' && *len > 0)
	{
		if (buffer[0] == '\0')
				*len = read(fd, buffer, BUFFER_SIZE);
		while (buffer[0] != '\n' && buffer[0] != '\0')
		{
			count = 0;
			retour[*count_ret] = buffer[0];
			*count_ret = *count_ret + 1;
			while (buffer[count] != '\0')
			{
				buffer[count] = buffer[count + 1];
				count++;
			}
		}
	}
	count = 0;
	while (buffer[count] != '\0')
	{
		buffer[count] = buffer[count + 1];
		count++;
	}
	retour[*count_ret] = '\0';
	return (buffer);
}
