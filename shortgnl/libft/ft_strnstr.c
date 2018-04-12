/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:21:56 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/22 23:06:27 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;
	int j;
	int curr;

	curr = len;
	i = 0;
	if (!*to_find)
		return (char *)str;
	while (str[i] && len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && curr)
		{
			if (!to_find[j + 1])
				return (char *)(str + i);
			j++;
			curr--;
		}
		i++;
		len--;
		curr = len;
	}
	return (0);
}
