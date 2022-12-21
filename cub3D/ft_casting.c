/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:54:37 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/25 17:04:11 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

void	ft_init_drp(t_casting *c, t_all *all, double pwd, t_image *tex)
{
	t_d_prm		*tdp;
	t_dda		*dda;

	tdp = c->tdp;
	dda = c->dda;
	tdp->l_hght = (int)((all->height / pwd));
	tdp->draw_st = -tdp->l_hght / 2 + all->height / 2;
	tdp->draw_e = tdp->l_hght / 2 + all->height / 2;
	if (tdp->draw_st < 0)
		tdp->draw_st = 0;
	if (tdp->draw_e >= all->height)
		tdp->draw_e = all->height;
	if (dda->side == 0)
		tdp->wall_x = all->player->plr_y + pwd * dda->r_dir_y;
	else
		tdp->wall_x = all->player->plr_x + pwd * dda->r_dir_x;
	tdp->wall_x -= floor(tdp->wall_x);
	tdp->texx = (int)(tdp->wall_x * (double)(tex->img_width));
	if (dda->side == 0 && dda->r_dir_x > 0)
		tdp->texx = tex->img_width - tdp->texx - 1;
	if (dda->side == 1 && dda->r_dir_y < 0)
		tdp->texx = tex->img_width - tdp->texx - 1;
	tdp->step = 1.0 * tex->img_height / tdp->l_hght;
	tdp->tex_pos = (tdp->draw_st - all->height / 2 + tdp->l_hght / 2)
		* tdp->step;
}

void	ft_free_cast(t_casting *cast)
{
	free(cast->dda);
	free(cast->tdp);
	free(cast);
}

t_image	*ft_tex_choose(t_casting *cast, t_all *all)
{
	if (cast->dda->side == 0)
	{
		if (cast->dda->r_dir_x < 0)
			return (all->north);
		else
			return (all->south);
	}
	else
	{
		if (cast->dda->r_dir_y < 0)
			return (all->west);
		else
			return (all->east);
	}
}

void	ft_draw_all_(t_all *all)
{
	int			w;
	double		p_w_dist;
	t_image		*texture;
	t_casting	*cast;
	double		*dist_buffer;

	w = 0;
	cast = ft_ret_cast();
	dist_buffer = (double *)malloc(sizeof(double) * all->width);
	if (dist_buffer == NULL)
		ft_error_foo("Malloc error\n");
	texture = NULL;
	while (w < all->width)
	{
		p_w_dist = ft_pependicular_dist(w, cast->dda, all);
		texture = ft_tex_choose(cast, all);
		ft_init_drp(cast, all, p_w_dist, texture);
		ft_draw(cast, all, w, texture);
		dist_buffer[w] = p_w_dist;
		w++;
	}
	ft_free_cast(cast);
	ft_draw_sprites(all, dist_buffer);
	free(dist_buffer);
	mlx_put_image_to_window(all->mlx, all->win, all->image->img, 0, 0);
}
