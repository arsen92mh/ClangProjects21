/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:05:52 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/25 17:05:58 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

int	ret_num(const char *line)
{
	int		big_num;

	big_num = ft_big_int_check(&line[0]);
	if (big_num == 0)
		return (2147483647);
	if (big_num == -1)
		return (-2147483648);
	else
		return (ft_atoi((char *)&line[0]));
}
