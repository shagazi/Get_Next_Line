/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:35:09 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/24 16:10:43 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *output;

	output = malloc(sizeof(t_list));
	if (!output)
		return (NULL);
	if (!content)
	{
		content_size = 0;
		output->content = NULL;
		output->next = NULL;
		return (output);
	}
	output->content_size = content_size;
	output->content = malloc(content_size);
	if (!output->content)
		return (NULL);
	output->content = ft_memcpy(output->content, content, output->content_size);
	output->next = NULL;
	return (output);
}
