/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:28:51 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/18 19:12:19 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	detect_overloop(void *dst, const void *src, size_t len)
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

void	*ft_memmove(void *dst, const void *src, size_t l)
{
	size_t	i;
	int		detect;

	i = 0;
	if (dst != 0 || src != 0)
	{
		detect = detect_overloop(dst, src, l);
		if (detect == 0 || (&dst[i] < &src[i]))
		{
			while (i < l)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				i++;
			}
		}
		else
		{
			while (l > 0)
			{
				((unsigned char *)dst)[l - 1] = ((unsigned char *)src)[l - 1];
				l--;
			}
		}
	}
	return (dst);
}
