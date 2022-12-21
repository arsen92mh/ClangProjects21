/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:07:46 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/18 19:10:33 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *b, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*a;

	i = 0;
	j = 0;
	x = 0;
	a = (char *)hay;
	if (b[0] == 0 || (&a[0] == &b[0]))
		return (&a[0]);
	while (b[j] != '\0')
		j++;
	while (i < len && a[i] != '\0')
	{
		while (a[i + x] == b[x] && i + x <= len)
		{
			x++;
			if (x == j)
				return (&a[i]);
		}
		x = 0;
		i++;
	}
	return (NULL);
}
