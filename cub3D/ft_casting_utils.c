/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:54:13 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/23 19:28:13 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

void	ft_draw(t_casting *cast, t_all *all, int x, t_image *txt)
{
	int				i;
	unsigned long	color;
	double			texy;

	i = 0;
	texy = (int)cast->tdp->tex_pos & (txt->img_height - 1);
	while (i < cast->tdp->draw_st)
		my_mlx_pix_put(all->image, x, i++, all->c_clr);
	while (cast->tdp->draw_st < cast->tdp->draw_e)
	{
		if (x == all->width - 1 && i == all->height - 1)
			return ;
		color = (int)get_color(txt, cast->tdp->texx, texy);
		my_mlx_pix_put(all->image, x, cast->tdp->draw_st, color);
		cast->tdp->tex_pos += cast->tdp->step;
		texy = (int)cast->tdp->tex_pos & (txt->img_height - 1);
		i++;
		cast->tdp->draw_st++;
	}
	while (i < all->height)
	{
		if (x == all->width - 1 && i == all->height - 1)
			return ;
		my_mlx_pix_put(all->image, x, i++, all->f_clr);
	}
}

void	ft_step_n_side_dist(t_dda *dda, t_all *all)
{
	if (dda->r_dir_x < 0)
	{
		dda->step_x = -1;
		dda->s_dist_x = (all->player->plr_x - dda->map_x) * dda->d_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->s_dist_x = (dda->map_x + 1.0 - all->player->plr_x) * dda->d_dist_x;
	}
	if (dda->r_dir_y < 0)
	{
		dda->step_y = -1;
		dda->s_dist_y = (all->player->plr_y - dda->map_y) * dda->d_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->s_dist_y = (dda->map_y + 1.0 - all->player->plr_y) * dda->d_dist_y;
	}
}

void	ft_hit_wall(t_dda *dda, t_all *all)
{
	while (dda->hit == 0)
	{
		if (dda->s_dist_x < dda->s_dist_y)
		{
			dda->s_dist_x += dda->d_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->s_dist_y += dda->d_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (all->map[dda->map_x][dda->map_y] == '1')
			dda->hit = 1;
	}
}

double	ft_perpendicular_dist_calculation(t_dda *dda, t_all *all)
{
	double			ret;

	if (dda->side == 0)
		ret = (dda->map_x - all->player->plr_x
				+ (1 - dda->step_x) / 2) / dda->r_dir_x;
	else
		ret = (dda->map_y - all->player->plr_y
				+(1 - dda->step_y) / 2) / dda->r_dir_y;
	return (ret);
}

double	ft_pependicular_dist(int w, t_dda *dda, t_all *all)
{
	dda->camera_x = 2 * w / (double)all->width - 1;
	dda->r_dir_x = all->player->dir_x + all->player->pln_x * dda->camera_x;
	dda->r_dir_y = all->player->dir_y + all->player->pln_y * dda->camera_x;
	dda->map_x = all->player->plr_x;
	dda->map_y = all->player->plr_y;
	dda->d_dist_x = fabs(1 / dda->r_dir_x);
	dda->d_dist_y = fabs(1 / dda->r_dir_y);
	dda->hit = 0;
	ft_step_n_side_dist(dda, all);
	ft_hit_wall(dda, all);
	return (ft_perpendicular_dist_calculation(dda, all));
}
