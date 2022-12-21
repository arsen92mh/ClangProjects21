/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:42:44 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:43:40 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void	type_parser(const char *str, t_p_t *options)
{
	size_t i;

	i = 1;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '*'
	|| str[i] == '.' || str[i] == '-' || str[i] == ' ')
	{
		if (str[i] == ' ' && options->space == 0)
			options->space = 1;
		i++;
	}
	options->type = str[i];
	if (options->type != 'd' && options->type != 'i' && options->type != 'c'
	&& options->type != 's' && options->type != '%' && options->type != 'x' &&
	options->type != 'X' && options->type != 'p' && options->type != 'u')
		options->error = 1;
	options->length = i + 1;
}

void	precision_parser(const char *str, t_p_t *options, va_list *argptr)
{
	size_t i;

	i = 0;
	while (str[i] != '.' && str[i] != options->type)
		i++;
	if (str[i++] == '.')
	{
		options->precision_indicator = 1;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
		{
			if (str[i] == '*')
				options->precision = va_arg(*argptr, int);
			else
				options->precision = ft_atoi((char*)&str[i]);
		}
	}
	if (options->precision < 0)
	{
		options->precision_indicator = 0;
		options->precision = 0;
	}
}

void	flags_width_parser(const char *str, t_p_t *options, va_list *argptr)
{
	size_t i;

	i = 1;
	while (str[i] == '0' || str[i] == '-' || str[i] == ' ')
	{
		if (str[i] == '0')
			options->zero_flag = 1;
		if (str[i] == '-')
			options->minus_flag = 1;
		i++;
	}
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
	{
		if (str[i] == '*')
			options->width = va_arg(*argptr, int);
		else
			options->width = ft_atoi((char*)&str[i]);
		if (options->width < 0)
		{
			options->minus_flag = 1;
			options->width *= -1;
		}
	}
	if (options->minus_flag == 1)
		options->zero_flag = 0;
}

void	main_parser(const char *str, t_p_t *options, va_list *argptr)
{
	options->type = 0;
	options->length = 0;
	options->zero_flag = 0;
	options->minus_flag = 0;
	options->precision = 0;
	options->precision_indicator = 0;
	options->width = 0;
	options->sxt_len = 0;
	options->error = 0;
	options->space = 0;
	type_parser(str, options);
	if (options->error == 1)
		return ;
	flags_width_parser(str, options, argptr);
	precision_parser(str, options, argptr);
	if (options->space == 1)
		ft_write(' ', options);
}
