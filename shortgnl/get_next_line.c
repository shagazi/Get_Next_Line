/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 09:59:22 by aschnapp          #+#    #+#             */
/*   Updated: 2018/04/05 15:25:09 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	get_next_line(const int fd, char **line)
{
	char	*buf;
	int		ret;
	char	*tmp;

	ERR_CHECK(!line, -1);
	ERR_CHECK(fd < 0, -1);
	*line = malloc(2);
	buf = malloc(2);
	ft_bzero(*line, 2);
	ft_bzero(buf, 2);
	ERR_CHECK(!line || !buf, -1);
	ERR_CHECK((ret = read(fd, buf, !!BUFF_SIZE)) < 0, -1);
	ERR_CHECK((*buf == '\n'), 1);
	ERR_CHECK((ret == 0), 0);
	*line[0] = buf[0];
	while ((ret = read(fd, buf, !!BUFF_SIZE)))
	{
		if (*buf == '\n' || ret == 0)
			break ;
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	free(buf);
	return (1);
}
