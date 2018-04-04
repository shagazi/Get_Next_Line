/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:33:57 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/04 16:36:48 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char			*return_buff(int fd)
{
	char	*buff;
	char	*fileread;
	int		returnread;
	char	*tmp;

	if (fd == -1)
	{
		ft_putstr("Failed to open file. Please enter a file name.\n");
		exit(1);
	}
	fileread = ft_strnew(0);
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((returnread = read(fd, buff, BUFF_SIZE)))
	{
		buff[returnread] = '\0';
		tmp = fileread;
		if (tmp)
			free(tmp);
		fileread = ft_strjoin(tmp, buff);
	}
	free(buff);
	return (fileread);
}

static char		*return_line(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(0);
	while ((*str)[i] != '\0')
	{
		tmp[i] = (*str)[i];
		if ((*str)[i] == '\n')
		{
			(*str) = ft_strchr((*str), '\n') + 1;
			tmp[i] = '\0';
			return (tmp);
		}
		i++;
	}
	//free(tmp);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *tmp;

	// **line = '\0';
	if (tmp == '\0')
		tmp = return_buff(fd);
	*line = return_line(&tmp);
	printf("%s\n", *line);
	if (*line != '\0')
		return (1);
	if (*line == '\0')
		return (0);
	return (-1);
	return (0);
}
