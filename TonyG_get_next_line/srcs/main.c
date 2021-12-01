/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguayaguay@student.42queb>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:26:26 by aguay             #+#    #+#             */
/*   Updated: 2021/11/24 13:22:02 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	FILE *fp = fopen("test.txt", "r");

	fp = open("test.txt", "r");
	if (fp == NULL)
	{
		printf("Unable to open the file");
		return (0);
	}
	while (get_next_line(fp) != NULL)
		get_next_line(fp);
	fclose(fp);
}

