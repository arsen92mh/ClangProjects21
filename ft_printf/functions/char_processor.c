/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:43:31 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:43:32 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void		char_processor(t_p_t *options, va_list argptr)
{
	char	c;

	c = va_arg(argptr, int);
	if (options->minus_flag == 1)
	{
		ft_write(c, options);
		while (options->width-- > 1)
			ft_write(' ', options);
	}
	else
	{
		while (options->width-- > 1)
			ft_write(' ', options);
		ft_write(c, options);
	}
}
