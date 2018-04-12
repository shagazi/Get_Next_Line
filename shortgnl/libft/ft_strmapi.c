/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:01:37 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 20:52:43 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	char	*head;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	newstr = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!newstr)
		return (NULL);
	head = newstr;
	while (*s)
	{
		*newstr = f(i, *s);
		newstr++;
		s++;
		i++;
	}
	*newstr = 0;
	return (head);
}
