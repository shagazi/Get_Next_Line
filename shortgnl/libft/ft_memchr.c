/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:52:32 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/22 21:38:55 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sptr;

	sptr = (unsigned char *)s;
	while ((*sptr != (unsigned char)c) && n && *sptr)
	{
		sptr++;
		n--;
	}
	return (*sptr == (unsigned char)c) ? sptr : NULL;
}
