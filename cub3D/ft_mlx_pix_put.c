/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pix_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:28:14 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/22 22:27:47 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

void	my_mlx_pix_put(t_data *d, int y, int x, unsigned long c)
{
	char			*dst;

	dst = d->addr + (x * d->l_l + y * (d->b_p_p / 8));
	*(unsigned long *)dst = c;
}

unsigned long	get_color(t_image *data, int texx, int texy)
{
	unsigned long	color;
	char			*dst;

	dst = data->addr + (texy * data->l_length + texx * (data->bpp / 8));
	color = *(unsigned long *)dst;
	return (color);
}
