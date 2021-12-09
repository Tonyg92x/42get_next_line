/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:02 by aguay             #+#    #+#             */
/*   Updated: 2021/12/09 11:10:07 by aguay            ###   ########.fr       */
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
	retour = malloc(1000000000000);
	ptr = buffer;
	len = 1;
	if (buffer[0] != '\0')
		ptr = ft_get(buffer, &len, fd, retour, &count_ret);
	else
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1 || len == 0)
		{
			free (retour);
			return (NULL);
		}
		ptr = ft_get(buffer, &len, fd, retour, &count_ret);
	}
	if (len == 0 && retour[0] == '\0')
	{
		free (retour);
		return (NULL);
	}
	return (retour);
}

char	*ft_get(char	*buffer, int *len, int fd, char *retour,int *count_ret)
{
	int	count;

	if (ft_protection(&buffer, &retour, count_ret))
		return (retour);
	while (buffer[0] != '\n' && *len > 0)
	{
		if (buffer[0] == '\0' && buffer[0] == '\0')
				*len = read(fd, buffer, BUFFER_SIZE);
		while (buffer[0] != '\n' && buffer[0] != '\0')
		{
			count = 0;
			retour[*count_ret] = buffer[0];
			(*count_ret)++;
			while (buffer[count] != '\0')
			{
				buffer[count] = buffer[count + 1];
				count++;
			}
		}
	}
	if (ft_protection(&buffer, &retour, count_ret))
		return (retour);
	retour[*count_ret] = '\0';
	return (buffer);
}

bool ft_protection(char **buffer, char **retour, int *count_ret)
{
	int	count;

	count = 0;
	if ((*buffer)[0] == '\n')
	{
		(*retour)[(*count_ret)] = '\n';
		(*retour)[(*count_ret) + 1] = '\0';
		while ((*buffer)[count] != '\0')
		{
			(*buffer)[count] = (*buffer)[count + 1];
			count++;
		}
		return (true);
	}
	else if ((*buffer)[0] == '\n' && (*buffer)[1] != '\0')
	{
		while ((*buffer)[count] != '\0')
		{
			(*buffer)[count] = (*buffer)[count + 1];
			count++;
		}
	}
	return (false);
}

// char	*ft_realloc(char *ptr)
// {
// 	char	*ptr2;

// 	ptr2 = ptr;
	
// }