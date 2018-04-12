/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:32:19 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/24 00:02:51 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_last(const char *s)
{
	int i;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		s++;
		i++;
	}
	while (*(s + 1))
		s++;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		s--;
		i++;
	}
	return (i);
}

static int	test(const char s)
{
	return (s == ' ' || s == '\t' || s == '\n');
}

char		*ft_strtrim(char const *s)
{
	int i;

	if (!s)
		return (NULL);
	while (test(*s))
		s++;
	i = find_last(s);
	return (ft_strsub(s, 0, ft_strlen((char *)s) - i));
}
