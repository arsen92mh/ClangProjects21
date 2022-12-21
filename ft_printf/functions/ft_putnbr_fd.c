/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:43:55 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:44:09 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

int		ft_min(t_p_t *options)
{
	ft_write('2', options);
	return (-147483648);
}

void	ft_putnbr_fd(int n, t_p_t *options)
{
	if (n < 0)
	{
		if (n == -2147483648)
			n = ft_min(options);
		n = n * -1;
		ft_putnbr_fd(n, options);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, options);
		ft_putnbr_fd(n % 10, options);
	}
	else
	{
		ft_write(n + '0', options);
	}
}
