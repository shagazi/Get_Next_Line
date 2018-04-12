/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:44:11 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/24 16:05:04 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!n)
		return (0);
	while (n)
	{
		*(char *)dst = *(char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return ((char *)dst + 1);
		src = (char *)src + 1;
		dst = (char *)dst + 1;
		n--;
	}
	return (NULL);
}
