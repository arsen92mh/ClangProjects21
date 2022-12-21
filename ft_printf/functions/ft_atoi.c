/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:43:48 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:44:09 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int		ft_atoi(char *c)
{
	int i;
	int pos_neg;
	int num;

	i = 0;
	pos_neg = 1;
	num = 0;
	while ((c[i] >= 9 && c[i] <= 13) || c[i] == 32)
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			pos_neg = -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		num = num * 10 + (c[i] - '0');
		i++;
	}
	return (num * pos_neg);
}
