/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialiser_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:06:55 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/22 23:25:38 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

t_player	*ft_init_player(void)
{
	t_player	*tmp;

	tmp = (t_player *)malloc(sizeof(t_player));
	if (!tmp)
		ft_error_foo("Malloc error\n");
	tmp->plr_x = 0;
	tmp->plr_y = 0;
	tmp->pln_x = 0;
	tmp->pln_y = 0;
	tmp->dir_x = 0;
	tmp->dir_y = 0;
	return (tmp);
}

t_list	*ft_start_init(void)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		ft_error_foo("Malloc error\n");
	tmp->map = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	ft_set_config_null(t_config *config)
{
	config->width = -1;
	config->height = -1;
	config->north = 0;
	config->south = 0;
	config->west = 0;
	config->east = 0;
	config->sprite = 0;
	config->config_complete = 0;
	config->map_start = 0;
	config->floor[0] = -1;
	config->floor[1] = -1;
	config->floor[2] = -1;
	config->ceiling[0] = -1;
	config->ceiling[1] = -1;
	config->ceiling[2] = -1;
	config->sprites = 0;
	config->screenshot = 0;
}

void	ft_player(int x, int i, t_player *player, char orient)
{
	player->plr_x = x + 0.5;
	player->plr_y = i + 0.5;
	if (orient == 'N')
	{
		player->pln_y = 0.66;
		player->dir_x = -1;
	}
	if (orient == 'E')
	{
		player->pln_x = 0.66;
		player->dir_y = 1;
	}
	if (orient == 'S')
	{
		player->pln_y = -0.66;
		player->dir_x = 1;
	}
	if (orient == 'W')
	{
		player->pln_x = -0.66;
		player->dir_y = -1;
	}
}
