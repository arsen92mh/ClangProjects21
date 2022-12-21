/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:10:15 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/24 21:14:17 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void	ft_tex_form_check(char *texture, size_t len)
{
	char	*str;
	size_t	ln;

	str = ft_strnstr(texture, ".xpm", len);
	if (!str)
		ft_error_foo("invalid texture format, 'xpm' needed\n");
	ln = ft_strlen(str);
	if (ln != 4)
		ft_error_foo("invalid texture format, 'xpm' needed\n");
}

void	ft_tex_fill(const char *line, t_config *config, size_t len)
{
	char	**texture;

	texture = NULL;
	if ((ft_strnstr(line, "NO ", len)) != NULL)
		texture = &config->north;
	if ((ft_strnstr(line, "SO ", len)) != NULL)
		texture = &config->south;
	if ((ft_strnstr(line, "WE ", len)) != NULL)
		texture = &config->west;
	if ((ft_strnstr(line, "EA ", len)) != NULL)
		texture = &config->east;
	if ((ft_strnstr(line, "S ", len)) != NULL)
		texture = &config->sprite;
	if (texture && ft_strchr(line, '.'))
	{
		*texture = ft_strdup(ft_strchr(line, '.'));
		if (texture && *texture == NULL)
			ft_error_foo("Malloc error\n");
		ft_tex_form_check(*texture, len);
		config->config_complete++;
	}
}

void	ft_check_trash(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != 'N' && str[i] != 'E' && str[i] != 'W'
		&& str[i] != 'S' && str[i] != 'F' && str[i] != 'R'
		&& str[i] != 'C')
		i++;
	while (j < i)
	{
		if (str[j++] != ' ')
			ft_error_foo("Trash in config\n");
	}
}

void	ft_config_management(const char *line, t_config *config)
{
	char	**texture;
	size_t	len;
	char	*c;
	int		compl;

	texture = NULL;
	compl = config->config_complete;
	len = ft_strlen(line);
	if (config->map_start == 0 && line[0] != '\0')
		ft_check_trash(line);
	if (ft_strnstr(line, "R ", len) != NULL)
		return (ft_screen_resolution(line, config));
	c = ft_strnstr(line, "F ", len);
	if (c != NULL)
		return (ft_floor_ceiling(c, config->floor, config));
	c = ft_strnstr(line, "C ", len);
	if (c != NULL)
		return (ft_floor_ceiling(c, config->ceiling, config));
	ft_tex_fill(line, config, len);
	if (compl == config->config_complete && line[0] != '\0')
		ft_error_foo("Unexpected params in config part/check spaces\n");
}
