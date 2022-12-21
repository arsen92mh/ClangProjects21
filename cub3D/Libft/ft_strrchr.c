/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:52:41 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/18 19:10:38 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*a;
	char	b;

	i = 0;
	a = (char *)s;
	b = (char)c;
	while (a[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (a[i] == b)
			return (&a[i]);
		i--;
	}
	return (NULL);
}
