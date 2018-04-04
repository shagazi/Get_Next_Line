/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:05:42 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/04 16:18:02 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// char			*return_buff(int fd);
// char		*return_line(char **str);

int			main(int argc, char *argv[])
{
	int		fd;
	char	**line;
	int		linereturn;
	// char	*returnbuff;

	linereturn = 2;
	line = (char **)malloc(sizeof(char) * 0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		// returnbuff = return_buff(fd);
		// return_line(&returnbuff);
		while (linereturn != 0)
			linereturn = get_next_line(fd, line);
		close(fd);
	}
	//free(&line);
	while(1)
		;
	return (0);
}
