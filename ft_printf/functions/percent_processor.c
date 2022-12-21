/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:44:45 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:44:48 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void	percent_processor(t_p_t *options, va_list argptr)
{
	char c;

	(void)argptr;
	if (options->minus_flag == 1)
	{
		ft_write('%', options);
		while (options->width-- > 1)
			ft_write(' ', options);
	}
	else
	{
		if (options->zero_flag == 1)
			c = '0';
		else
			c = ' ';
		while (options->width-- > 1)
			ft_write(c, options);
		ft_write('%', options);
	}
}
