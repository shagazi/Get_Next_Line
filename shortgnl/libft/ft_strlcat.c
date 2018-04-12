/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:18:07 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 22:21:56 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dstlen;
	size_t srclen;

	i = ft_strlen(dst);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	if (dstsize < dstlen + 1)
		return (srclen + dstsize);
	while (i < dstsize - 1)
	{
		*(dst + i) = *src;
		i++;
		src++;
	}
	*(dst + i) = 0;
	return (dstlen + srclen);
}
