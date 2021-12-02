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
	size_t		len;
	char		*line;
	char		*temp;
	static char	buffer[BUFFER_SIZE + 1];
	char		*ptr;

	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	line = ft_calloc(BUFFER_SIZE + 1, 1);
	ptr = buffer;
	if (*ptr)
	{
		ft_putstr_getnext_fd(ptr, 1);
		temp = ft_strjoin(temp, ptr);
		if (ft_strchr(ptr, '\n'))
		{
			ptr = line_fix(ptr);
			return (temp);
		}
		ft_memset(ptr, '\0', BUFFER_SIZE);
	}
	//	2) Imprime le reste de la phrase (jusqu'au \n)
	len = read(fd, line, BUFFER_SIZE);
	if (len == 0)
		return (NULL);
	line[BUFFER_SIZE] = '\0';
	if (ft_strchr(line, '\n'))
	{
		ft_putstr_getnext_fd(line, 1);
		temp = ft_strjoin(temp, line);
		line = line_fix(line);
		buff_set(line, ptr);
		free(line);
	}
	else
	{
		while(!ft_strchr(line, '\n'))
		{
			ft_putstr_getnext_fd(line, 1);
			temp = ft_strjoin(temp, line);
			free(line);
			len = read(fd, line, BUFFER_SIZE);
		}
		ft_putstr_getnext_fd(line, 1);
		temp = ft_strjoin(temp, line);
		line = line_fix(line);
		buff_set(line, ptr);
	}	
	return (temp);
}

char	*ft_strdup(const char *src)
{
	int		count;
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	count = 0;
	while (src[count] && src[count] != '\n')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retour;
	int		count;
	int		count_retour;

	if (!s1 || !s2)
		return (NULL);
	retour = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (retour == NULL)
		return (NULL);
	count = -1;
	count_retour = 0;
	while (s1[++count])
		retour[count_retour++] = s1[count];
	count = 0;
	while (s2[count] && s2[count] != '\n')
	{
		retour[count_retour] = s2[count];
		count++;
		count_retour++;
	}
	retour[count_retour] = '\0';
	return (retour);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return ((void *)ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	count;
	char	*d;

	d = b;
	count = 0;
	while (count < len)
	{
		d[count] = (char) c;
		count++;
	}
	return (b);
}
