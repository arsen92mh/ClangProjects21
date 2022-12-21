/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:27:46 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/24 01:21:11 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void	ft_nullchar_check_2(t_list *start, int i)
{
	if (start->next == NULL || start->prev == NULL)
		ft_error_foo("Invalid map char combitation\n");
	if (!start->next->map[i] || !start->prev->map[i + 1]
		|| (start->prev->map[i + 1] == ' ') || !start->prev->map[i - 1]
		|| (start->prev->map[i - 1] == ' ') || !start->next->map[i + 1]
		|| (start->next->map[i + 1] == ' ') || !start->next->map[i - 1]
		|| (start->next->map[i - 1] == ' ') || !start->prev->map[i]
		|| !start->map[i + 1] || !start->map[i - 1])
		ft_error_foo("Invalid map char combitation\n");
}

void	ft_nullchar_check(t_list *start, int i)
{
	char	a;

	ft_nullchar_check_2(start, i);
	a = start->prev->map[i];
	if (a != '1' && a != '0' && a != '2' && a != 'N'
		&& a != 'S' && a != 'E' && a != 'W')
		ft_error_foo("IInvalid map char combitation\n");
	a = start->next->map[i];
	if (a != '1' && a != '0' && a != '2' && a != 'N'
		&& a != 'S' && a != 'E' && a != 'W')
		ft_error_foo("Invalid map char combitation\n");
	a = start->map[i + 1];
	if (a != '1' && a != '0' && a != '2' && a != 'N'
		&& a != 'S' && a != 'E' && a != 'W')
		ft_error_foo("Invalid map char combitation\n");
	a = start->map[i - 1];
	if (a != '1' && a != '0' && a != '2' && a != 'N'
		&& a != 'S' && a != 'E' && a != 'W')
		ft_error_foo("Invalid map char combitation\n");
}
