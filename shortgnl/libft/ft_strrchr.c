/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:08:38 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 22:24:18 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *temp;

	temp = NULL;
	if (!c)
	{
		while (*s)
			s++;
		return (char *)s;
	}
	while (*s)
	{
		if (*s == c)
			temp = (char *)s;
		s++;
	}
	return (temp);
}
