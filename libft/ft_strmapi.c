/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:04:36 by kulrike           #+#    #+#             */
/*   Updated: 2020/11/12 16:33:22 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	res = (char*)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	while (j < i)
	{
		res[j] = f((unsigned int)j, s[j]);
		j++;
	}
	res[j] = '\0';
	return (res);
}
