/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:22:26 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/17 23:22:31 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void	ft_ull_putnbr_fd(unsigned long long n, t_p_t *options)
{
	if (n > 9)
	{
		ft_uint_putnbr_fd(n / 16, options);
		ft_uint_putnbr_fd(n % 16, options);
	}
	else
	{
		ft_write(n + '0', options);
	}
}
