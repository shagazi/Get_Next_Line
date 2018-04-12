/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:44:11 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 22:20:49 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		loc;
	char	*dstptr;
	char	*srcptr;

	dstptr = (char *)dst;
	srcptr = (char *)src;
	if (dst - src == 0)
		return (dst);
	else if (dst - src < 0)
		loc = 0;
	else
		loc = len - 1;
	while (len)
	{
		dstptr[loc] = srcptr[loc];
		if (dst - src < 0)
			loc++;
		else
			loc--;
		len--;
	}
	return (dst);
}
