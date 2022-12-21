/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:44:14 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:44:25 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void	ft_uint_putnbr_fd(unsigned int n, t_p_t *options)
{
	if (n > 9)
	{
		ft_uint_putnbr_fd(n / 10, options);
		ft_uint_putnbr_fd(n % 10, options);
	}
	else
	{
		ft_write(n + '0', options);
	}
}
