/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:27:56 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/02 20:31:55 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libftprintf.h"

int	error(va_list *argptr)
{
	va_end(*argptr);
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	va_list		argptr;
	t_p_t		options;

	i = 0;
	if (!str)
		return (-1);
	options.format_length = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			main_parser(&str[i], &options, &argptr);
			if (options.error == 1)
				return (error(&argptr));
			i += options.length;
			start_process(&options, argptr);
		}
		else
			ft_write(str[i++], &options);
	}
	va_end(argptr);
	return (options.format_length);
}
