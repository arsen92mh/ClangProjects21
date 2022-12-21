/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsen <arsen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:52:14 by kulrike           #+#    #+#             */
/*   Updated: 2021/03/09 16:22:12 by arsen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		last_free(char **store)
{
	free(*store);
	*store = NULL;
	return (0);
}

int		free_all(char **store, char **line, char *to_free)
{
	if (store)
	{
		free(*store);
		*store = NULL;
	}
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (to_free)
	{
		free(to_free);
		to_free = NULL;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int			rd;
	char		buf[BUFFER_SIZE + 1];
	static char	*store;
	char		*n_ptr;
	char		*to_free;

	if (!line || BUFFER_SIZE < 1 || (read(fd, buf, 0)) < 0)
		return (-1);
	while ((rd = read(fd, buf, BUFFER_SIZE)))
	{
		buf[rd] = '\0';
		to_free = store;
		if (!(store = (store) ? (ft_strjoin(to_free, buf)) : (ft_strdup(buf))))
			return (free_all(&store, line, to_free));
		if (ft_strchr(store, '\n'))
			break ;
	}
	if (!(to_free = (store) ? store : ft_strdup("")))
		return (free_all(&store, line, to_free));
	if ((n_ptr = ft_strchr(to_free, '\n')))
		*n_ptr = '\0';
	if ((!(store = (n_ptr) ? ft_strdup(++n_ptr) : ft_strdup(""))) ||
	(!(*line = ft_strjoin(to_free, ""))))
		return (free_all(&store, line, to_free));
	return (rd == 0 && ft_strlen(store) == 0 && !n_ptr) ? last_free(&store) : 1;
}
