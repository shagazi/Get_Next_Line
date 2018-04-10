/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linetest3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:33:57 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/10 02:39:43 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char		*return_line(char **fileread)
{
	int		i;
	char 	*newline;
	char	*tmp;

	i = 0;
	tmp = *fileread;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			newline = ft_strncpy(ft_strnew(i), tmp, i);
			*fileread = ft_strchr(tmp, '\n') + 1;
			return (newline);
		}
		i++;
	}
	if(/*tmp > 0 && */ tmp[i] == '\0')
	{
		newline = ft_strncpy(ft_strnew(i + 1), (*fileread), i + 1);
		return (newline);
	}
	return (0);
}

char			*return_buff(int fd, char **fileread)
{
	char	*buffer;
	char	*tmp;
	// char 	*line;
	int		bytesread;

	*fileread = ft_strnew(0);
	tmp = ft_strnew(0);
	// line = ft_strnew(0);
	buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((bytesread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytesread] = '\0';
		tmp = *fileread;
		*fileread = ft_strjoin(tmp, buffer);
		free(tmp);
		if (*fileread != '\0')
		// {
		// 	line = return_line(fileread);
			return (return_line(fileread));
		// }
	}
	free(buffer);
	free(fileread);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *fileread;
	 //
	// if (!tmpstr)
	// 	tmpstr = malloc(sizeof(char *));
	if (fd < 0 || !line) // !line means **line is empty, null, no memory
		return (-1);
	// if (read(fd, buffer, BUFF_SIZE) == 0)
	// 	return (0);
	if (fileread == '\0')
		**line = *return_buff(fd, &fileread);
	if (*line != '\0')
		return (1);
	else
	{
		// free(fileread);
		return (0);
	}
}
