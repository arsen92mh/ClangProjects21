/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:50:34 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/05 01:28:36 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*z;
	unsigned char	y;
	size_t			i;

	i = 0;
	z = b;
	y = c;
	while (i < len)
	{
		z[i] = y;
		i++;
	}
	return (z);
}
