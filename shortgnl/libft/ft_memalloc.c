/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:44:11 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 21:56:07 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *ptr;
	char *head;

	head = (char *)malloc(size);
	ptr = head;
	if (ptr == NULL)
		return (NULL);
	while (size)
	{
		*ptr = '\0';
		ptr++;
		size--;
	}
	return ((void *)head);
}
