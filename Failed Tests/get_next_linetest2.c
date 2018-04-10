/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linetest2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:33:57 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/10 02:39:37 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char		*return_line(char **str)
{
	int		i;
	char 	*newline;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
		{
			newline = ft_strncpy(ft_strnew(i), (*str), i);
			(*str) = ft_strchr((*str), '\n') + 1;
			return (newline);
		}
		i++;
	}
	if(i > 0 && (*str)[i] == '\0')
	{
		newline = ft_strncpy(ft_strnew(i + 1), (*str), i + 1);
		*str += i;
		return (newline);
	}
	return (0);
}

static int			read_buff(int fd, char **fileread)
{
	char	*buff;
	int		returnread;
	char	*tmp;

	// *fileread = ft_strnew(0);
	tmp = ft_strnew(0);
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((returnread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[returnread] = '\0';
		tmp = *fileread;
		*fileread = ft_strjoin(tmp, buff);
		free(tmp);
	}
	if (returnread == -1)
	{
		free(*fileread);
		return (-1);
	}
	if (returnread == 0)
	{
		free(*fileread);
		return (0);
	}
	free(buff);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *tmpstr;

	if (fd < 0 || !line || BUFF_SIZE < 0) // !line means **line is empty, null, no memory
		return (-1);
	if (tmpstr == '\0')
		if (read_buff(fd, &tmpstr) == -1)
			return (-1);
	*line = return_line(&tmpstr);
	if (*line != '\0')
		return (1);
	else
	{
	//	free(*tmpstr);
		return (0);
	}
}
