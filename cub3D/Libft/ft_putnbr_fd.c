/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:00:37 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/18 19:04:40 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_min(int fd)
{
	write(fd, "2", 1);
	return (-147483648);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		print_char('-', fd);
		if (n == -2147483648)
			n = ft_min(fd);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		print_char(n + '0', fd);
	}
}
