/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:14:28 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/24 16:38:13 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*head;

	head = NULL;
	while (lst)
	{
		temp2 = malloc(sizeof(t_list));
		if (!temp2)
			return (NULL);
		temp2 = f(lst);
		if (!head)
		{
			head = temp2;
			temp1 = temp2;
		}
		else
		{
			temp1->next = temp2;
			temp1 = temp1->next;
		}
		lst = lst->next;
	}
	return (head);
}
