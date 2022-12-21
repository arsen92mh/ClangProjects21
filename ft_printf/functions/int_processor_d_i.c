/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_processor_d_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:44:37 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:44:49 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void	minus_print(t_p_t *options, int d, int i, int wdt)
{
	int prc;

	prc = options->precision;
	while (prc-- > i)
	{
		ft_write('0', options);
		wdt--;
	}
	ft_putnbr_fd(d, options);
	while (wdt-- - i > 0)
		ft_write(' ', options);
}

void	zero(t_p_t *options, int i, int d)
{
	while (options->width > i && options->width-- > options->precision)
		ft_write(' ', options);
	if (d < 0)
		ft_write('-', options);
	while (options->precision-- > i)
		ft_write('0', options);
	ft_putnbr_fd(d, options);
}

void	negative_d(t_p_t *options)
{
	if (options->minus_flag == 1 || (options->zero_flag == 1 &&
	options->precision_indicator == 0))
		ft_write('-', options);
	options->width--;
}

void	int_main(t_p_t *options, int i, int d)
{
	if (d == 0 && options->precision == 0 && options->precision_indicator == 1)
	{
		while (options->width-- > 0)
			ft_write(' ', options);
		return ;
	}
	if (d < 0)
		negative_d(options);
	if (options->minus_flag == 1)
	{
		minus_print(options, d, i, options->width);
		return ;
	}
	if (options->zero_flag == 0 || (options->zero_flag == 1 &&
	options->precision_indicator == 1))
	{
		zero(options, i, d);
		return ;
	}
	if (options->precision_indicator == 0)
	{
		while (options->width-- > i)
			ft_write('0', options);
		ft_putnbr_fd(d, options);
	}
}

void	int_processor_d_i(t_p_t *options, va_list argptr)
{
	int	d;
	int	i;
	int a;

	d = va_arg(argptr, int);
	i = 0;
	a = d;
	if (a == 0)
		i = 1;
	while (a != 0)
	{
		a /= 10;
		i++;
	}
	if (i > options->width && d != 0)
		options->width = i;
	int_main(options, i, d);
}
