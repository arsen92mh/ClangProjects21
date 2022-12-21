/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:13:14 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/17 18:13:15 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void	start_process(t_p_t *options, va_list argptr)
{
	if (options->type == 'd' || options->type == 'i')
		int_processor_d_i(options, argptr);
	if (options->type == '%')
		percent_processor(options, argptr);
	if (options->type == 's')
		str_processor(options, argptr);
	if (options->type == 'u')
		uint_processor(options, argptr);
	if (options->type == 'x' || options->type == 'X')
		sixteen_processor(options, argptr);
	if (options->type == 'p')
		ptr_processor(options, argptr);
	if (options->type == 'c')
		char_processor(options, argptr);
}
