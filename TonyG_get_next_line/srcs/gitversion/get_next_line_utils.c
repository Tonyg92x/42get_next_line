/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:25:57 by aguay             #+#    #+#             */
/*   Updated: 2021/12/02 12:51:10 by aguay            ###   ########.fr       */
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

bool	ft_strchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == '\0')
	{
		while (len > 0)
		{
			s++;
			len--;
		}
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
		{
			return (true);
		}
		s++;
	}
	return (false);
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

char	*line_fix(char *line)
{
	int	i;
	
	while(line[0] != '\n')
	{
		i = 0;
		while (line[i])
		{
			line[i] = line[i + 1];
			i++;
		}
	}
	i = 0;
	while (line[i])
	{
		line[i] = line[i + 1];
		i++;
	}
	return (line);
}

char	*buff_set(char *line, char *buffer)
{
	int		i;
	
	i = 0;
	while (line[i])
	{
		buffer[i] = line[i];
		i++;
	}
	return (buffer);
}