/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:36:06 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/24 01:32:41 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void	ft_map_check(const char *line, t_config *config)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	j = 0;
	r = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			j++;
		if (ft_strchr("NEWS012", line[i]) != NULL)
			r++;
		i++;
	}
	if (i == j && line[0] != '\0')
	{
		config->map_start = 0;
		ft_error_foo("Only empty lines allowed in config part\n");
	}
	if (i == j + r && line[0] != '\0')
		config->map_start = 1;
}

t_list	*find_last_list(t_list *start)
{
	while (start->next)
		start = start->next;
	return (start);
}

t_list	*add_map_line(char *line, t_list *start)
{
	t_list	*tmp;
	t_list	*last;

	if (start->map)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (tmp == NULL)
			ft_error_foo("Malloc error\n");
		last = find_last_list(start);
		tmp->map = ft_strdup(line);
		if (tmp->map == NULL)
			ft_error_foo("Malloc error\n");
		tmp->prev = last;
		last->next = tmp;
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		start->map = ft_strdup(line);
		if (start->map == NULL)
			ft_error_foo("Malloc error\n");
		return (start);
	}
}

void	ft_textures_check(const char *tex)
{
	int		opn;
	int		rd;

	opn = open(tex, O_RDONLY);
	rd = read(opn, O_RDONLY, 0);
	if (opn < 0 || rd < 0)
		ft_error_foo("invalid texture\n");
	close(opn);
}

void	ft_main_parser(char **line, t_config *config, t_list *start)
{
	t_list	*tmp;
	size_t	len;

	tmp = NULL;
	len = ft_strlen(*line);
	if (ft_strchr(*line, '\t') != NULL)
		ft_error_foo("No tabs\n");
	if (config->map_start == 0 && line != NULL)
		ft_map_check(*line, config);
	if (config->map_start == 0 && line != NULL)
	{
		if (config->config_complete < 10)
			ft_config_management(*line, config);
	}
	else if (config->map_start == 1 && line)
	{
		if (config->config_complete != 9)
			ft_error_foo("Invalid config positions\n");
		ft_textures_check(config->east);
		ft_textures_check(config->north);
		ft_textures_check(config->west);
		ft_textures_check(config->south);
		ft_textures_check(config->sprite);
		tmp = add_map_line(*line, start);
	}
}
