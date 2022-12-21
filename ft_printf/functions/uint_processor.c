/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:45:23 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:45:25 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int					ft_uint_bitness_count(unsigned int a)
{
	int				i;

	i = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void				uint_minus(t_p_t *options, unsigned int d, int i)
{
	while (options->precision-- > i)
	{
		ft_write('0', options);
		options->width--;
	}
	ft_uint_putnbr_fd(d, options);
	options->width -= i;
	while (options->width-- > 0)
		ft_write(' ', options);
}

void				uint_zero0(t_p_t *options, int i, unsigned int d)
{
	while (options->width > i && options->width-- > options->precision)
		ft_write(' ', options);
	while (options->precision-- > i)
		ft_write('0', options);
	ft_uint_putnbr_fd(d, options);
}

void				uint_main(t_p_t *options, int i, unsigned int d)
{
	if (d == 0 && options->precision == 0 && options->precision_indicator == 1)
	{
		while (options->width-- > 0)
			ft_write(' ', options);
		return ;
	}
	if (options->minus_flag == 1)
	{
		uint_minus(options, d, i);
		return ;
	}
	if (options->zero_flag == 0 || (options->zero_flag == 1 &&
	options->precision_indicator == 1))
	{
		uint_zero0(options, i, d);
		return ;
	}
	if (options->precision_indicator == 0)
	{
		while (options->width-- > i)
			ft_write('0', options);
		ft_uint_putnbr_fd(d, options);
		return ;
	}
}

void				uint_processor(t_p_t *options, va_list argptr)
{
	unsigned int	d;
	int				i;

	d = va_arg(argptr, int);
	i = ft_uint_bitness_count(d);
	if (i > options->width && d != 0)
		options->width = i;
	uint_main(options, i, d);
}
