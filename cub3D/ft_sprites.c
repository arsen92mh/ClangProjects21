/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:04:14 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/22 21:28:39 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

t_sprite	*ft_ret_tmp(int i, int j)
{
	t_sprite	*tmp;

	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	if (tmp ==NULL)
		ft_error_foo("Mem error getting sprite coords\n");
	tmp->x = (double)i + 0.5;
	tmp->y = (double)j + 0.5;
	return (tmp);
}

t_sprite	**ft_get_sprite_coords(t_all *all)
{
	t_sprite	**tmp;
	int			i;
	int			j;
	int			x;

	i = 0;
	j = 0;
	x = 0;
	tmp = (t_sprite **)malloc(sizeof(t_sprite *) * all->sprite_amount);
	if (tmp == NULL)
		ft_error_foo("Mem error getting sprite coords\n");
	while (i < all->player->map)
	{
		while (all->map[i][j] != '\0')
		{
			if (all->map[i][j] == '2')
				tmp[x++] = ft_ret_tmp(i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (tmp);
}
