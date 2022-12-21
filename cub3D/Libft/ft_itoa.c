/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:43:46 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/18 19:01:24 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_char_len(int n)
{
	size_t	i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	ret_char(int num)
{
	if (num >= 0 && num <= 9)
		return (num);
	return (ret_char(num / 10));
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*a;

	i = ft_char_len(n);
	a = (char *)malloc(sizeof(char) * (i + 1));
	if (a == NULL)
		return (NULL);
	a[0] = '0';
	a[i] = '\0';
	while (n)
	{
		if (n < 0)
		{
			a[0] = '-';
			if (n == -2147483648)
			{
				a[--i] = '8';
				n /= 10;
			}
			n *= -1;
		}
		a[--i] = n % 10 + '0';
		n /= 10;
	}
	return (a);
}
