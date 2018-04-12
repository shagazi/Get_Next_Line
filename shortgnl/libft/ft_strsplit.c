/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschnapp <aschnapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 22:54:35 by aschnapp          #+#    #+#             */
/*   Updated: 2018/02/23 22:13:25 by aschnapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define CHECK(x, c) ((x) == (c))
#define RCHECK(x, c) ((x) != (c))

#define DECL int i = 0,j = 0,k = 0

static int	output_size(char const *str, char ***output, char c)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (CHECK(str[i], c))
		{
			size++;
			i++;
			while (str[i] && CHECK(str[i], c))
				i++;
		}
		else
			i++;
	}
	if (RCHECK(str[i - 1], c))
		size++;
	*output = malloc((size + 1) * sizeof(char *));
	if (!*output)
		return (0);
	return (1);
}

static int	item_size(char const *str, char **output, char c)
{
	DECL;
	while (str[i])
	{
		if (RCHECK(str[i], c))
			k++;
		if (CHECK(str[i], c) && k)
		{
			output[j] = malloc(k + 1);
			if (!output[j])
				return (0);
			j++;
			k = 0;
		}
		i++;
	}
	if (RCHECK(str[i - 1], c))
	{
		output[j] = malloc(k + 1);
		if (!output[j])
			return (0);
	}
	return (1);
}

static void	fill(char const *str, char **output, char c)
{
	DECL;
	while (str[i])
	{
		if (RCHECK(str[i], c) && str[i])
		{
			output[j][k] = str[i];
			k++;
		}
		if (CHECK(str[i], c) && k && str[i])
		{
			output[j][k] = 0;
			k = 0;
			j++;
		}
		i++;
	}
	if (RCHECK(str[i - 1], c))
	{
		output[j][k] = 0;
		output[j + 1] = (char *)NULL;
	}
	else
		output[j] = (char *)NULL;
}

static int	nullstr(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (RCHECK(str[i], c))
			return (0);
		i++;
	}
	return (1);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**output;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	output = NULL;
	output = malloc(1 * sizeof(char *));
	if (!output)
		return (NULL);
	output[0] = NULL;
	if (nullstr(str, c))
		return (output);
	i = output_size(str, &output, c);
	if (!i)
		return (NULL);
	j = item_size(str, output, c);
	if (!j)
		return (NULL);
	fill(str, output, c);
	return (output);
}
