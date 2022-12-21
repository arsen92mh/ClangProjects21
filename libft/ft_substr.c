/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:29:38 by kulrike           #+#    #+#             */
/*   Updated: 2020/11/11 13:41:34 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*a;

	i = 0;
	if (s == 0)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if (start >= i)
	{
		a = (char*)malloc(sizeof(char) * 1);
		a[0] = 0;
		return (a);
	}
	i = 0;
	a = (char*)malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
