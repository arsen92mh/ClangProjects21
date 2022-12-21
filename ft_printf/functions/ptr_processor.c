/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:44:55 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:44:59 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void					ptr_prc_1(t_p_t *options, int i, unsigned long long d)
{
	while (options->precision > i)
	{
		ft_write('0', options);
		options->width--;
		options->precision--;
	}
	write(1, "0x", 2);
	if (options->precision_indicator == 0 ||
	(options->precision_indicator == 1 && options->precision == 0 && d != 0))
	{
		ft_ptr_putnbr(d, options);
		options->width -= i;
	}
	options->format_length += 2;
	while (options->width-- > 0)
		ft_write(' ', options);
	while (options->width > 0)
	{
		ft_write(' ', options);
		options->width--;
	}
}

void					ptr_zero(t_p_t *options, int i, unsigned long long d)
{
	while (options->width > i && options->width-- > options->precision)
		ft_write(' ', options);
	write(1, "0x", 2);
	options->format_length += 2;
	while (options->precision-- > i)
		ft_write('0', options);
	ft_ptr_putnbr(d, options);
}

void					ptr_indctr(t_p_t *options, int i, unsigned long long d)
{
	while (options->width-- > i)
		ft_write('0', options);
	write(1, "0x", 2);
	options->format_length += 2;
	ft_ptr_putnbr(d, options);
}

void					ptr_main(t_p_t *options, int i, unsigned long long d)
{
	options->width -= 2;
	if (d == 0 && options->precision == 0 &&
	options->precision_indicator == 1 && options->minus_flag == 0)
	{
		while (options->width-- > 0)
			ft_write(' ', options);
		write(1, "0x", 2);
		options->format_length += 2;
		return ;
	}
	if (options->minus_flag == 1)
	{
		ptr_prc_1(options, i, d);
		return ;
	}
	if (options->zero_flag == 0 || (options->zero_flag == 1 &&
	options->precision_indicator == 1))
	{
		ptr_zero(options, i, d);
		return ;
	}
	if (options->precision_indicator == 0)
		ptr_indctr(options, i, d);
}

void					ptr_processor(t_p_t *options, va_list argptr)
{
	unsigned long long	d;
	unsigned long long	a;

	d = va_arg(argptr, unsigned long long);
	a = d;
	if (a == 0)
		options->sxt_len = 1;
	while (a)
	{
		options->sxt_len++;
		a /= 16;
	}
	ptr_main(options, options->sxt_len, d);
}
