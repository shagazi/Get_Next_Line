/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:33:57 by shagazi           #+#    #+#             */
/*   Updated: 2018/04/04 22:51:10 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*return_buff(int fd)
{
	char	*buff;
	char	*fileread;
	int		returnread;
	char	*tmp;

	if (fd == -1)
		return (NULL);
	fileread = ft_strnew(0);
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((returnread = read(fd, buff, BUFF_SIZE)))
	{
		buff[returnread] = '\0';
		tmp = fileread;
		fileread = ft_strjoin(tmp, buff);
		free(tmp);
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
			free(tmp);
			return (tmp);
		}
		// if(ft_strcmp(tmp, (*str)) == 0 && (*str)[i] != '\n')
		if(ft_strcmp(tmp, (*str)) == 0 && (*str)[i] != '\n')
		{
			ft_bzero(str, ft_strlen(*str));
			free(tmp);
			return (tmp);
		}
		i++;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *tmpstr;

	if (tmpstr == '\0')
		if(!(tmpstr = return_buff(fd)))
			return(-1);
	*line = return_line(&tmpstr);
	if (*line != '\0')
		return (1);
	if (*line == '\0')
		return (0);
	return (-1);
}
