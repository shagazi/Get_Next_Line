/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:05:42 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/04 23:23:43 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

int			main(int argc, char *argv[])
{
	int		fd;
	char	**line;
	int		linereturn;
	int count = 0;

	linereturn = 1;
	line = (char **)malloc(sizeof(char) * 0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (linereturn != 0)
		{
			linereturn = get_next_line(fd, line);
			if (linereturn == 1)
				count++;
		}
		printf("%d\n", count);
		close(fd);
	}
	while(1)
		;
	return (0);
}
