/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:06:24 by kulrike           #+#    #+#             */
/*   Updated: 2020/11/10 15:04:12 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char*)s;
	while (a[i] != '\0')
	{
		if (a[i] == c)
			return (&a[i]);
		i++;
	}
	if (c == 0)
		return (&a[i++]);
	return (NULL);
}
