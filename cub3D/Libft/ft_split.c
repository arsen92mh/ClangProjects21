/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:50:34 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/18 19:08:13 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arr_amount(char const *str, char c)
{
	size_t	i;
	size_t	wrd_amount;
	size_t	wrd_index;

	i = 0;
	wrd_amount = 0;
	wrd_index = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && wrd_index == 0)
		{
			wrd_index = 1;
			wrd_amount++;
		}
		if (str[i] == c && wrd_index == 1)
			wrd_index = 0;
		i++;
	}
	return (wrd_amount);
}

size_t	ft_find_indexes(const char *s, char c, int mode, size_t from)
{
	if (mode == 1)
	{
		while (s[from] == c && s[from] != '\0')
			from++;
	}
	else if (mode == -1)
	{
		while (s[from] != c && s[from] != '\0')
			from++;
	}
	return (from);
}

char	**ft_ustroy_destroy(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	x;
	size_t	g;

	i = 0;
	x = 0;
	if (s == 0)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_arr_amount(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (i < ft_arr_amount(s, c))
	{
		x = ft_find_indexes(s, c, 1, x);
		g = ft_find_indexes(s, c, -1, x);
		res[i] = ft_substr(s, x, g - x);
		if (res[i] == NULL)
			return (ft_ustroy_destroy(res));
		x = g;
		i++;
	}
	res[i] = NULL;
	return (res);
}
