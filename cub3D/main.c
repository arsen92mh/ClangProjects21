/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:33:36 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/24 23:07:42 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

char	**ft_map_construct(t_list *start, t_player *player)
{
	char		**map;
	t_list		*p_start;
	int			x;

	x = 0;
	p_start = start;
	while (p_start != NULL)
	{
		p_start = p_start->next;
		x++;
	}
	player->map = x;
	map = (char **)malloc(sizeof(char *) * x);
	if (map == NULL)
		ft_error_foo("Malloc error\n");
	x = 0;
	while (start != NULL)
	{
		map[x] = ft_strdup(start->map);
		if (map[x] == NULL)
			ft_error_foo("Malloc error\n");
		x++;
		start = start->next;
	}
	return (map);
}

void	ft_free_start(t_list *start)
{
	t_list		*to_free;

	while (start)
	{
		to_free = start->next;
		free(start->map);
		free(start);
		start = to_free;
	}
}

void	ft_gnl(char *line, t_config *config, t_list *start, char *map)
{
	int			gnl_res;
	int			opn;
	int			folder;

	folder = 1;
	opn = open(map, O_RDONLY);
	if (opn < 0)
		ft_error_foo("map file access/read error\n");
	gnl_res = get_next_line(opn, &line);
	while (gnl_res == 1)
	{
		ft_main_parser(&line, config, start);
		folder = 0;
		free(line);
		gnl_res = get_next_line(opn, &line);
	}
	if (gnl_res == -1)
		ft_error_foo("Invalid GNL return\n");
	if (folder == 1)
		ft_error_foo("Trying to pass folder/empty file as a map?\n");
	if (config->map_start == 0)
		ft_error_foo("Map not found\n");
	ft_main_parser(&line, config, start);
	free(line);
}

int	main(int argc, char *argv[])
{
	char		*line;
	t_config	config;
	t_list		*start;
	char		**map;
	t_player	*player;

	line = NULL;
	start = ft_start_init();
	player = ft_init_player();
	ft_set_config_null(&config);
	ft_arg_validator(argc, argv, &config);
	ft_gnl(line, &config, start, argv[1]);
	ft_map_line_vd(start, player, &config);
	map = ft_map_construct(start, player);
	ft_free_start(start);
	ft_cub_start(&config, map, player);
	return (0);
}
