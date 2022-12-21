/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:52:14 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/24 00:39:09 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

int	get_next_line(int fd, char **line)
{
	char	*buf;
	char	ch;
	int		res;
	int		i;

	i = 0;
	ch = '\0';
	buf = malloc(100000);
	*line = buf;
	res = read(fd, &ch, 1);
	while (res > 0 && ch != '\n')
	{
		buf[i++] = ch;
		res = read(fd, &ch, 1);
	}
	buf[i] = '\0';
	if (res < 0)
		ft_error_foo("Invalid GNL return\n");
	return (res);
}
