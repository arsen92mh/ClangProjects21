/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:54:10 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/05 01:28:08 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	t;

	i = ft_strlen(src);
	d = ft_strlen(dst);
	if (d >= size)
		return (size + i);
	if (size == 0)
		return (i);
	if (dst == NULL || src == NULL)
		return (0);
	t = i + d;
	i = 0;
	while (size - d - 1 > 0 && src[i] != '\0')
	{
		dst[d] = src[i];
		i++;
		d++;
	}
	dst[d] = '\0';
	return (t);
}
