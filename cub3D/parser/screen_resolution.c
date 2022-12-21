/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:23:37 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/25 17:04:08 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

size_t	ft_get_num_len(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

void	ft_res_writing(int ind, t_config *conf, int num)
{
	if (ind > 2)
		ft_error_foo("Invalid resolution config\n");
	if (ind == 0)
		conf->width = num;
	else
		conf->height = num;
	conf->config_complete++;
}

void	ft_scr_trash(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] != ' ')
			ft_error_foo("Trash in resolution config\n");
	}
}

void	ft_screen_resolution(const char *line, t_config *conf)
{
	size_t	i;
	size_t	num_len;
	int		num;
	int		ind;

	i = 0;
	ind = 0;
	if (conf->width != -1 || conf->height != -1)
		ft_error_foo("One of config line trigger is reused\n");
	while (line[i])
	{
		num_len = 1;
		if (ind == 2)
			return (ft_scr_trash(&line[i]));
		if ((line[i] > '0' && line[i] <= '9') || line[i] == '-')
		{
			num = ret_num(&line[i]);
			num_len = ft_get_num_len(&line[i]);
			ft_res_writing(ind, conf, num);
			ind++;
		}
		i += num_len;
	}
}
