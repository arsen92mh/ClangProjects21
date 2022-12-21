/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:44:22 by kulrike           #+#    #+#             */
/*   Updated: 2021/01/16 18:44:24 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libftprintf.h"

void	ft_write(char c, t_p_t *options)
{
	write(1, &c, 1);
	options->format_length++;
}