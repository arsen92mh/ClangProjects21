/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:10:36 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/24 20:25:33 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

void	ft_max_res(t_all *all, t_config *config)
{
	if (config->width > 16383)
		all->width = 16383;
	else
		all->width = config->width;
	if (config->height > 16383)
		all->height = 16383;
	else
		all->height = config->height;
}

void	ft_min_res(t_config *config)
{
	if (config->width < 50)
		config->width = 50;
	if (config->height < 50)
		config->height = 50;
}

void	ft_screen(t_all *all, t_config *config)
{
	int				width;
	int				height;

	width = 0;
	height = 0;
	if (config->width < 0 || config->height < 0)
		ft_error_foo("Negative resolution isnt allowed\n");
	mlx_get_screen_size(all->mlx, &width, &height);
	if (config->screenshot == 0)
	{
		ft_min_res(config);
		if (config->width > width)
			all->width = width - 1;
		else
			all->width = config->width;
		if (config->height > height)
			all->height = height - 1;
		else
			all->height = config->height;
	}
	else
		ft_max_res(all, config);
}
