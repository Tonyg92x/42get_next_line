/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:26:26 by aguay             #+#    #+#             */
/*   Updated: 2021/12/07 11:20:43 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
    ssize_t    fd;
    char    *test;

        fd = open("test.txt", O_RDONLY);
	puts("-------------main----------");
    do
    {
        test = get_next_line(fd);
        printf("|%s|\n", test);
        if (test)
            free(test);
    } while (test != NULL);
    if (test)
        free(test);
    close(fd);
    return (0);
}

