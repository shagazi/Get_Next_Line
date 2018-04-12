/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:06:21 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 20:54:34 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *newstr;
	char *head;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!newstr)
		return (NULL);
	head = newstr;
	while (*s1 || *s2)
	{
		if (*s1)
		{
			*newstr = *s1;
			s1++;
		}
		else if (*s2)
		{
			*newstr = *s2;
			s2++;
		}
		newstr++;
	}
	*newstr = 0;
	return (head);
}
