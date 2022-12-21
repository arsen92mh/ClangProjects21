/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:45:13 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:45:15 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void		minus1_str_print(t_p_t *options, int i, const char *str)
{
	if (options->precision_indicator == 0)
	{
		while (str[i])
			ft_write(str[i++], options);
		while (i++ < options->width)
			ft_write(' ', options);
	}
	if (options->precision_indicator == 1)
	{
		while (str[i] && i < options->precision)
			ft_write(str[i++], options);
		while (i++ < options->width)
			ft_write(' ', options);
	}
}

void		minus0_print(t_p_t *options, int len, const char *str, int i)
{
	if (options->zero_flag == 1)
	{
		if (options->precision_indicator == 0)
		{
			while (options->width-- > len)
				ft_write('0', options);
			while (str[i])
				ft_write(str[i++], options);
		}
		if (options->precision_indicator == 1)
		{
			while (options->width-- > options->precision ||
			options->precision > len++)
				ft_write('0', options);
			while (str[i] && i < options->precision)
				ft_write(str[i++], options);
		}
	}
}

void		indicator1(t_p_t *options, int len, const char *str, int i)
{
	if (options->precision > len)
		options->precision = len;
	while (options->width > options->precision ||
	options->width > len)
	{
		ft_write(' ', options);
		options->width--;
	}
	while (options->precision > 0 && str[i])
	{
		ft_write(str[i++], options);
		options->precision--;
		len--;
		options->width--;
	}
	while (options->width-- > options->precision)
		ft_write(' ', options);
}

void		zero0(t_p_t *options, int len, const char *str, int i)
{
	if (options->precision_indicator == 0)
	{
		while (options->width-- > len)
			ft_write(' ', options);
		while (str[i])
			ft_write(str[i++], options);
	}
	if (options->precision_indicator == 1)
		indicator1(options, len, str, i);
}

void		str_processor(t_p_t *options, va_list argptr)
{
	char	*str;
	int		i;
	int		len;

	str = va_arg(argptr, char*);
	i = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (options->minus_flag == 1)
		minus1_str_print(options, i, str);
	if (options->minus_flag == 0)
	{
		if (options->zero_flag == 1)
			minus0_print(options, len, str, i);
		if (options->zero_flag == 0)
			zero0(options, len, str, i);
	}
}
