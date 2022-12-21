/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:43:23 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/24 01:17:54 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void	ft_other_chars(t_list *start, t_player *plr, int x, t_config *conf)
{
	size_t	i;
	char	*str;

	i = 0;
	str = start->map;
	while (str[i])
	{
		if (ft_strchr(" 102NEWS", str[i]) != NULL)
		{
			if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E'
				|| str[i] == 'W')
				ft_player(x, i, plr, str[i]);
			if (str[i] == '2')
				conf->sprites++;
			i++;
		}
		else
			ft_error_foo("Map includes invalid chars\n");
	}
	if (ft_strlen(str) == 0 && start->next != NULL)
		ft_error_foo("map should be end max one empty line\n");
}

void	ft_player_check(t_list *start, int i, int *p_pl)
{
	char	a;

	if (!start->prev->map[i] || !start->next->map[i]
		|| !start->map[i + 1] || !start->map[i - 1])
		ft_error_foo("Bad player position\n");
	else
	{
		a = start->prev->map[i];
		if (a != '0' && a != '1' && a != '2')
			ft_error_foo("Bad player position\n");
		a = start->next->map[i];
		if (a != '0' && a != '1' && a != '2')
			ft_error_foo("Bad player position\n");
		a = start->map[i + 1];
		if (a != '0' && a != '1' && a != '2')
			ft_error_foo("Bad player position\n");
		a = start->map[i - 1];
		if (a != '0' && a != '1' && a != '2')
			ft_error_foo("Bad player position\n");
	}
	*p_pl += 1;
}

void	ft_map_char_surrounded_by(char c, t_list *start, int i, int *p_pl)
{
	if (c == '0' || c == '2')
		ft_nullchar_check(start, i);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ft_player_check(start, i, p_pl);
}

void	ft_check_char_combinations(t_list *tmp, int *p_pl)
{
	size_t	i;
	char	*str;

	i = 0;
	str = tmp->map;
	while (str[i] != '\0')
	{
		ft_map_char_surrounded_by(str[i], tmp, i, p_pl);
		i++;
	}
}

void	ft_map_line_vd(t_list *start, t_player *plr, t_config *conf)
{
	int		pl;
	int		*p_pl;
	int		x;

	pl = 0;
	p_pl = &pl;
	x = 0;
	while (start != NULL)
	{
		ft_other_chars(start, plr, x, conf);
		ft_check_char_combinations(start, p_pl);
		x++;
		start = start->next;
	}
	if (pl != 1)
		ft_error_foo("Invalid number of players\n");
}
