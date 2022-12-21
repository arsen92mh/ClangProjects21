/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixteen_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:45:04 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:45:07 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void				ft_sxt_bitness_count(unsigned int a, t_p_t *options)
{
	int i;

	i = 0;
	if (a == 0)
		i = 1;
	while (a)
	{
		i++;
		a /= 16;
		if (a == 16)
			i++;
	}
	options->sxt_len = i;
}

void				sxt_minus(t_p_t *options, unsigned int d, int i)
{
	while (options->precision-- > i)
	{
		ft_write('0', options);
		options->width--;
	}
	ft_sxt_putnbr_fd(d, options, options->type);
	options->width -= i;
	while (options->width-- > 0)
		ft_write(' ', options);
	while (options->width > 0)
	{
		ft_write(' ', options);
		options->width--;
	}
}

void				sxt_zero(t_p_t *options, unsigned int d, int i)
{
	while (options->width > i && options->width-- > options->precision)
		ft_write(' ', options);
	while (options->precision-- > i)
		ft_write('0', options);
	ft_sxt_putnbr_fd(d, options, options->type);
}

void				sxt_main(t_p_t *options, int i, unsigned int d)
{
	ft_sxt_bitness_count(d, options);
	i = options->sxt_len;
	if (d == 0 && options->precision == 0 && options->precision_indicator == 1)
	{
		while (options->width-- > 0)
			ft_write(' ', options);
		return ;
	}
	if (options->minus_flag == 1)
	{
		sxt_minus(options, d, i);
		return ;
	}
	if (options->zero_flag == 0 || (options->zero_flag == 1 &&
	options->precision_indicator == 1))
	{
		sxt_zero(options, d, i);
		return ;
	}
	if (options->precision_indicator == 0)
	{
		while (options->width-- > i)
			ft_write('0', options);
		ft_sxt_putnbr_fd(d, options, options->type);
	}
}

void				sixteen_processor(t_p_t *options, va_list argptr)
{
	unsigned int	d;
	int				i;

	i = 0;
	d = va_arg(argptr, int);
	sxt_main(options, i, d);
}
