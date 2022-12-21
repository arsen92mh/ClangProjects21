/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scr_res_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:20:50 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/25 16:38:20 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

int	ft_big_int_util(const char *str, int min)
{
	int	j;

	if (min == -1)
		j = 1;
	else
		j = 0;
	if (str[j++] > '2' || str[j++] > '1' || str[j++] > '4'
		|| str[j++] > '7' || str[j++] > '4' || str[j++] > '8'
		|| str[j++] > '3' || str[j++] > '6' || str[j++] > '4'
		|| (str[j] > '7' && min == 0) || (str[j] > '8' && min == -1))
	{
		return (min);
	}
	return (1);
}

int	ft_big_int_check(const char *str)
{
	int	i;
	int	ind;
	int	min;

	i = 0;
	ind = 0;
	min = 0;
	if (str[i] == '-')
	{
		if (str[i + 1] >= '0' && str[i++ + 1] <= '9')
			min = -1;
		else
			ft_error_foo("incorrect minus position\n");
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i + min == 10)
		return (ft_big_int_util(str, min));
	if (i + min > 10)
		return (min);
	return (1);
}
