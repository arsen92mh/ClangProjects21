/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr_cast_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:48:48 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/22 22:05:02 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

void	ft_spr_calc_2(t_sprcast *spr, t_all *all)
{
	if (spr->dr_en_y > all->height)
		spr->dr_en_y = all->height;
	else
		spr->dr_en_y = spr->dr_en_y;
	spr->spr_w = (abs((int)(all->width / (spr->tr_y))) / UDIV);
	spr->dr_st_x = -spr->spr_w / 2 + spr->spr_scr_x;
	if (spr->dr_st_x < 0)
		spr->dr_st_x = 0;
	spr->dr_en_x = spr->spr_w / 2 + spr->spr_scr_x;
	if (spr->dr_en_x >= all->width)
		spr->dr_en_x = spr->dr_en_x;
	spr->stripe = spr->dr_st_x;
}

void	ft_spr_calc_1(t_sprcast *spr, t_all *all, int x)
{
	spr->spr_x = all->sprites[spr->order[x]]->x - all->player->plr_x;
	spr->spr_y = all->sprites[spr->order[x]]->y - all->player->plr_y;
	spr->inv_det = 1.0 / (all->player->pln_x * all->player->dir_y
			- all->player->dir_x * all->player->pln_y);
	spr->tr_x = spr->inv_det * (all->player->dir_y * spr->spr_x
			- all->player->dir_x * spr->spr_y);
	spr->tr_y = spr->inv_det * (-all->player->pln_y * spr->spr_x
			+ all->player->pln_x * spr->spr_y);
	spr->spr_scr_x = (int)((all->width / 2)
			* (1 + spr->tr_x / spr->tr_y));
	spr->vmv_scr = (int)(VMOVE / spr->tr_y);
	spr->spr_hght = (abs((int)(all->height / (spr->tr_y))) / VDIV);
	spr->dr_st_y = -spr->spr_hght / 2
		+ all->height / 2 + spr->vmv_scr;
	if (spr->dr_st_y < 0)
		spr->dr_st_y = 0;
	spr->dr_en_y = spr->spr_hght / 2 + all->height / 2 + spr->vmv_scr;
	ft_spr_calc_2(spr, all);
}
