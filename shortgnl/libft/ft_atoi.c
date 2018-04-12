/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:10:29 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/22 21:04:03 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int i;
	int o;
	int sign;

	i = 0;
	o = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\r')
		|| (str[i] == '\f') || (str[i] == '\t'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		o *= 10;
		o += (str[i] - 48);
		i++;
	}
	return (o * sign);
}
