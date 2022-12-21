/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:24:27 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/17 23:24:29 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

char	ft_ptrc_chr(unsigned long long int n)
{
	char c;

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

void	ft_ptr_putnbr(unsigned long long n, t_p_t *options)
{
	char c;

	c = '\0';
	if (n > 16)
	{
		ft_ptr_putnbr(n / 16, options);
		ft_ptr_putnbr(n % 16, options);
	}
	else
	{
		if (n >= 10 && n <= 15)
			c = ft_ptrc_chr(n);
		else
			ft_ull_putnbr_fd(n, options);
		if (c != '\0')
			ft_write(c, options);
	}
}
