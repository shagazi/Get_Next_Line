/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:45:48 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 22:00:28 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *newstr;
	char *head;

	if (!s || !f)
		return (NULL);
	newstr = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!newstr)
		return (NULL);
	head = newstr;
	while (*s)
	{
		*newstr = f(*s);
		newstr++;
		s++;
	}
	*newstr = 0;
	return (head);
}
