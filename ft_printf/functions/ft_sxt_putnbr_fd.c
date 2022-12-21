/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sxt_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:44:03 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:44:10 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

char		ft_sxt_chr(unsigned long long int n)
{
	char	c;

	c = '\0';
	if (n == 10)
		c = 'a';
	else if (n == 11)
		c = 'b';
	else if (n == 12)
		c = 'c';
	else if (n == 13)
		c = 'd';
	else if (n == 14)
		c = 'e';
	else if (n == 15)
		c = 'f';
	return (c);
}

void		ft_sxt_putnbr_fd(unsigned int n, t_p_t *options, char type)
{
	char	c;

	c = '\0';
	if (n > 16)
	{
		ft_sxt_putnbr_fd(n / 16, options, type);
		ft_sxt_putnbr_fd(n % 16, options, type);
	}
	else
	{
		if (n >= 10 && n <= 15)
			c = ft_sxt_chr(n);
		else
			ft_uint_putnbr_fd(n, options);
		if (c != '\0')
		{
			if (type == 'X')
				c = c - 32;
			ft_write(c, options);
		}
	}
}
