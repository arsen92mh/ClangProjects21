/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:27:16 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/22 22:10:47 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

void	ft_spr_dist(t_all *all, t_sprcast *spr)
{
	int	x;

	x = 0;
	while (x < all->sprite_amount)
	{
		spr->order[x] = x;
		spr->distance[x] = pow(all->player->plr_x - all->sprites[x]->x, 2)
			+ pow(all->player->plr_y - all->sprites[x]->y, 2);
		x++;
	}
	x = 0;
}

void	ft_spr_sort(t_sprcast *spr, t_all *all)
{
	int	x;

	x = 0;
	while (x < all->sprite_amount)
	{
		if (spr->distance[x] < spr->distance[x + 1]
			&& x != all->sprite_amount - 1)
		{
			spr->num = spr->order[x];
			spr->dist = spr->distance[x];
			spr->order[x] = spr->order[x + 1];
			spr->distance[x] = spr->distance[x + 1];
			spr->order[x + 1] = spr->num;
			spr->distance[x + 1] = spr->dist;
			x = 0;
		}
		else
			x++;
	}
}

void	ft_tex_config(t_sprcast *spr, t_all *a)
{
	spr->d = (spr->y - spr->vmv_scr) * 256 - a->height
		* 128 + spr->spr_hght * 128;
	spr->texy = ((spr->d * a->sprite->img_height)
			/ spr->spr_hght) / 256;
	if (spr->texx == a->sprite->img_height - 1
		&& spr->texy == a->sprite->img_width - 1)
		spr->texy--;
}

void	ft_spr_calcs(t_sprcast *spr, t_all *a, double *buff, int x)
{
	unsigned long	color;

	ft_spr_calc_1(spr, a, x);
	while (spr->stripe < spr->dr_en_x)
	{
		spr->texx = (int)(256 * (spr->stripe - (-spr->spr_w
						/ 2 + spr->spr_scr_x)) * a->sprite->img_width
				/ spr->spr_w) / 256;
		if (spr->tr_y > 0 && spr->stripe > 0 && spr->stripe < a->width
			&& spr->tr_y < buff[spr->stripe])
		{
			spr->y = spr->dr_st_y;
			while (spr->y < spr->dr_en_y)
			{
				ft_tex_config(spr, a);
				color = get_color(a->sprite, spr->texx, spr->texy);
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pix_put(a->image, spr->stripe, spr->y, color);
				spr->y++;
			}
		}
		spr->stripe++;
	}
}

void	ft_draw_sprites(t_all *all, double *d_buff)
{
	int				x;
	t_sprcast		*spr;

	x = 0;
	spr = ft_init_spr(all);
	spr->num = 0;
	spr->dist = 0;
	ft_spr_dist(all, spr);
	ft_spr_sort(spr, all);
	while (x < all->sprite_amount)
	{
		ft_spr_calcs(spr, all, d_buff, x);
		x++;
	}
	free(spr->order);
	free(spr->distance);
	free(spr);
}
