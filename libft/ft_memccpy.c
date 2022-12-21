/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:40:48 by kulrike           #+#    #+#             */
/*   Updated: 2020/11/16 20:20:20 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		((unsigned char*)d)[i] = ((unsigned char*)s)[i];
		if (((unsigned char*)s)[i] == ((unsigned char)c))
			return (&((unsigned char*)d)[i + 1]);
		i++;
	}
	return (NULL);
}
