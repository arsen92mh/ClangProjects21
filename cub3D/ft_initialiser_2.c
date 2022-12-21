/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialiser_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:57:56 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/22 22:55:51 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

int	ft_rgb(int r, int g, int b)
{
	return (256 * 256 * r + 256 * g + b);
}

t_image	*ft_get_image(t_all *all, char *path)
{
	t_image			*t;

	t = (t_image *)malloc(sizeof(t_image));
	if (!t)
		ft_error_foo("Texture extracting failure\n");
	t->img = mlx_xpm_file_to_image(all->mlx, path,
			&t->img_width, &t->img_height);
	if (!t->img)
		ft_error_foo("Texture extracting failure\n");
	if (t->img_width != 64 && t->img_height != 64)
		ft_error_foo("Incorrect tex resolution, 64x64 is needed\n");
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->l_length, &t->endian);
	free(path);
	return (t);
}

void	ft_tex_init(t_all *tmp, t_config *conf)
{
	tmp->north = ft_get_image(tmp, conf->north);
	tmp->south = ft_get_image(tmp, conf->south);
	tmp->west = ft_get_image(tmp, conf->west);
	tmp->east = ft_get_image(tmp, conf->east);
	tmp->sprite = ft_get_image(tmp, conf->sprite);
	tmp->c_clr = ft_rgb(conf->ceiling[0], conf->ceiling[1], conf->ceiling[2]);
	tmp->f_clr = ft_rgb(conf->floor[0], conf->floor[1], conf->floor[2]);
	tmp->height_center = tmp->height / 2;
	tmp->width_center = tmp->width / 2;
}

void	ft_win_init(t_all *tmp)
{
	tmp->win = mlx_new_window(tmp->mlx, tmp->width, tmp->height, "cub3D");
	tmp->image->img = mlx_new_image(tmp->mlx, tmp->width, tmp->height);
	tmp->image->addr = mlx_get_data_addr(tmp->image->img, &tmp->image->b_p_p,
			&tmp->image->l_l, &tmp->image->endian);
}

t_all	*ft_init_all(t_config *conf, t_player *player, char **map)
{
	t_all	*tmp;

	tmp = (t_all *)malloc(sizeof(t_all));
	if (!tmp)
		ft_error_foo("Malloc error\n");
	tmp->player = player;
	ft_screen(tmp, conf);
	tmp->fov = M_PI / 3;
	tmp->mlx = mlx_init();
	if (!tmp->mlx)
		ft_error_foo("Malloc error\n");
	tmp->image = (t_data *)malloc(sizeof(t_data));
	if (!tmp->image)
		ft_error_foo("Malloc error\n");
	ft_win_init(tmp);
	ft_tex_init(tmp, conf);
	tmp->map = map;
	tmp->dist_to_pp = tmp->width_center / tan(tmp->fov / 2);
	tmp->sprite_amount = conf->sprites;
	tmp->sprites = ft_get_sprite_coords(tmp);
	tmp->screenshot = conf->screenshot;
	return (tmp);
}
