/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:16:47 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 23:19:48 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int nb)
{
	char	*s;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	s = (char *)malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		s[0] = '-';
		s[1] = 0;
		s = ft_strjoin(s, ft_itoa(nb * -1));
	}
	else if (nb >= 10)
		s = ft_strjoin(ft_itoa(nb / 10), ft_itoa(nb % 10));
	else if (nb < 10 && nb >= 0)
	{
		s[0] = nb + '0';
		s[1] = 0;
	}
	return (s);
}
