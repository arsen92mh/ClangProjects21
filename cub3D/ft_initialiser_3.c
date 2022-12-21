/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialiser_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:59:18 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/22 22:33:04 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

t_sprcast	*ft_init_spr(t_all *all)
{
	t_sprcast	*tmp;

	tmp = (t_sprcast *)malloc(sizeof(t_sprcast));
	if (!tmp)
		ft_error_foo("Malloc error\n");
	tmp->order = (int *)malloc(sizeof(int) * all->sprite_amount);
	if (!tmp->order)
		ft_error_foo("Malloc error\n");
	tmp->distance = (double *)malloc(sizeof(double) * all->sprite_amount);
	if (!tmp->distance)
		ft_error_foo("Malloc error\n");
	return (tmp);
}

t_dda	*ft_ret_dda(void)
{
	t_dda		*tmp;

	tmp = (t_dda *)malloc(sizeof(t_dda));
	if (!tmp)
		ft_error_foo("Malloc error\n");
	return (tmp);
}

t_d_prm	*ft_ret_tdp(void)
{
	t_d_prm		*tmp;

	tmp = (t_d_prm *)malloc(sizeof(t_d_prm));
	if (!tmp)
		ft_error_foo("Malloc error\n");
	return (tmp);
}

t_casting	*ft_ret_cast(void)
{
	t_casting	*cst;

	cst = (t_casting *)malloc(sizeof(t_casting));
	if (!cst)
		ft_error_foo("Malloc error\n");
	cst->dda = ft_ret_dda();
	cst->tdp = ft_ret_tdp();
	return (cst);
}
