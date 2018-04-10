/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:05:42 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/09 20:14:05 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>
#include <assert.h>

void extra()
{
	char *line;

	line = NULL;
	printf("%d\n", get_next_line(42, &line));
}

int			main(int argc, char *argv[])
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	assert(strcmp(line, "abcd") == 0);
	ret = get_next_line(p[0], &line);
	assert(ret == 0);
	extra();
	return (0);
}
