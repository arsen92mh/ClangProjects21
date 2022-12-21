/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:46:02 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/25 16:41:41 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void	ft_comma_amount(const char *str)
{
	size_t	i;
	int		ind;

	i = 0;
	ind = 0;
	while (str[i])
	{
		if (str[i] == ',')
			ind++;
		i++;
	}
	if (ind != 2)
		ft_error_foo("floor/ceiling ','\n");
}

void	ft_comma_check(const char *c, size_t len)
{
	size_t	i;
	int		ind;

	i = 0;
	ind = 1;
	ft_comma_amount(c);
	while (i++ < len)
	{
		if (ft_strchr("0123456789CF ,-", c[i]) == NULL)
			ft_error_foo("invalid chars in floor/ceiling config\n");
		if (c[i] >= '0' && c[i] <= '9')
			ind = 0;
		if (c[i] == ',')
		{
			if (ind == 1)
				ft_error_foo("floor/ceilinf ','\n");
			else
				ind = 1;
		}
	}
	if (ind == 1)
		ft_error_foo("floor/ceiling ','\n");
}

void	ft_floor_ceiling(const char *c, int *to_fill, t_config *config)
{
	size_t	i;
	size_t	len;
	int		j;
	size_t	x;

	i = 0;
	j = 0;
	len = ft_strlen(c);
	ft_comma_check(c, len);
	while (i < len)
	{
		x = 1;
		if ((c[i] > '0' && c[i] <= '9') || c[i] == '-')
		{
			if (j == 3 || to_fill[j] != -1)
				ft_error_foo("invalid F/C config\n");
			to_fill[j] = ret_num(&c[i]);
			x = ft_get_num_len(&c[i]);
			if (to_fill[j] < 0 || to_fill[j] > 255)
				ft_error_foo("invalid RGB color\n");
			j++;
		}
		i += x;
	}
	config->config_complete++;
}
