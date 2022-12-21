/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 03:57:02 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/23 19:23:27 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

int	ft_red_cross(void)
{
	exit(0);
	return (0);
}

void	ft_rotate(int keycode, t_player *p)
{
	double			r_speed;
	double			oldplanex;
	double			olddirx;

	if (keycode == 123)
		r_speed = 0.05;
	else
		r_speed = -0.05;
	olddirx = p->dir_x;
	p->dir_x = p->dir_x * cos(r_speed) - p->dir_y * sin(r_speed);
	p->dir_y = olddirx * sin(r_speed) + p->dir_y * cos(r_speed);
	oldplanex = p->pln_x;
	p->pln_x = p->pln_x * cos(r_speed) - p->pln_y * sin(r_speed);
	p->pln_y = oldplanex * sin(r_speed) + p->pln_y * cos(r_speed);
}

void	ft_step(int keycode, t_player *p, char **map)
{
	double			m_speed;

	m_speed = -0.2;
	if (keycode == 13 || keycode == 126 || keycode == 1 || keycode == 125)
	{
		if (keycode == 13 || keycode == 126)
			m_speed = 0.2;
		if (map[(int)(p->plr_x + p->dir_x * m_speed)][(int)(p->plr_y)] != '1')
			p->plr_x += p->dir_x * m_speed;
		if (map[(int)(p->plr_x)][(int)(p->plr_y + p->dir_y * m_speed)] != '1')
			p->plr_y += p->dir_y * m_speed;
	}
	if (keycode == 123 || keycode == 124)
		ft_rotate(keycode, p);
	if (keycode == 0 || keycode == 2)
	{
		if (keycode == 0)
			m_speed = 0.2;
		if (map[(int)(p->plr_x - p->pln_x * m_speed)][(int)(p->plr_y)] != '1')
			p->plr_x -= p->pln_x * m_speed;
		if (map[(int)(p->plr_x)][(int)(p->plr_y - p->pln_y * m_speed)] != '1')
			p->plr_y -= p->pln_y * m_speed;
	}
}

int	ft_key_press(int keycode, t_all *all)
{
	t_data	*i;

	if (keycode == 53)
		exit(0);
	i = (t_data *)malloc(sizeof(t_data));
	if (!i)
		ft_error_foo("Malloc Error\n");
	i->img = mlx_new_image(all->mlx, all->width, all->height);
	i->addr = mlx_get_data_addr(i->img, &i->b_p_p, &i->l_l, &i->endian);
	ft_step(keycode, all->player, all->map);
	mlx_destroy_image(all->mlx, all->image->img);
	mlx_clear_window(all->mlx, all->win);
	free(all->image);
	all->image = i;
	ft_draw_all_(all);
	return (1);
}

void	ft_cub_start(t_config *config, char **map, t_player *player)
{
	t_all			*all;
	int				x;
	int				y;
	int				*p_x;
	int				*p_y;

	p_x = &x;
	p_y = &y;
	all = ft_init_all(config, player, map);
	ft_draw_all_(all);
	if (all->screenshot == 1)
	{
		save_screenshot(all);
		exit(0);
	}
	mlx_hook(all->win, 2, 1L << 0, &ft_key_press, all);
	mlx_hook(all->win, 17, 1L << 0, &ft_red_cross, all);
	mlx_loop(all->mlx);
}
