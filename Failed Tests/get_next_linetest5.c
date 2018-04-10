/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linetest5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:33:57 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/10 02:39:26 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*return_buff(char *buffer, int bytesread)
{
	char	*tmp;
	char	*fileread3;

	tmp = ft_strnew(0);
	// fileread3 = (char *)malloc(sizeof(char) * 0);
	// while ((bytesread = read(fd, buffer, BUFF_SIZE)) > 0)
	// {
		buffer[bytesread] = '\0';
		// tmp = fileread3;
		fileread3 = ft_strjoin(tmp, buffer);
		// free(buffer);
		free(tmp);
		return(fileread3);
        //
		// if (*fileread != '\0')
		// {
		// 	line = return_line(fileread);
		// 	return (*line);
	// 	// }
	// }
	return (0);
}

char		*return_line(char **fileread2, int bytesread)
{
	int		i;
	char	*nline;
	char	*tmp;
	char	*lineread;

	i = 0;
	lineread = return_buff(*fileread2, bytesread);
	tmp = lineread;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			nline = ft_strncpy(ft_strnew(i), tmp, i);
			nline[i] = '\0';
			*fileread2 = ft_strchr(tmp, '\n') + 1;
			return (nline);
		}
		i++;
	}
	if(i > 0 && tmp[i] == '\0')
	{
		nline = ft_strncpy(ft_strnew(i + 1), tmp, i + 1);
		return (nline);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *buffer[fd_limit]; // *buffer[fd_limit] is for static holding
	char buffer2[BUFF_SIZE + 1] //This one is for read
	// *buffer[fd_limit]
	int bytesread;

	//bytesread = 0
	// while (strchr(buffer[fd], \n) == NULL)
		//read(buffer)
		// if br = 0, break;
	if (fd < 0 || !line || read(fd, buffer2, 0) < 0)
		return (-1);
		// if !(arr[fd])
			arr[fd] = strnew(0);
	//if (bytesread == 0)
	// 	buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	while((bytesread > 4) || (bytesread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytesread] = '\0';
		*line = return_line(&buffer, bytesread);
		bytesread -= ft_strlen(*line);
		if (*line != '\0')
			return (1);
	}
	if (bytesread == -1)
		return (-1);
	else
	{
//		free (buffer);
		return (0);
	}
}
