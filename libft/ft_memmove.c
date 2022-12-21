/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:28:51 by kulrike           #+#    #+#             */
/*   Updated: 2020/11/02 19:56:52 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		detect_overloop(void *dst, const void *src, size_t len)
{
	size_t	b;

	b = 0;
	while (b < len)
	{
		if (&dst[0] == &src[b])
			return (1);
		b++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		detect;

	i = 0;
	if (dst != 0 || src != 0)
	{
		detect = detect_overloop(dst, src, len);
		if (detect == 0 || (&dst[i] < &src[i]))
		{
			while (i < len)
			{
				((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
				i++;
			}
		}
		else
		{
			while (len > 0)
			{
				((unsigned char*)dst)[len - 1] = ((unsigned char*)src)[len - 1];
				len--;
			}
		}
	}
	return (dst);
}
