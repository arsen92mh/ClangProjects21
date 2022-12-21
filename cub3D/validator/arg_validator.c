/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:03:07 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/23 20:45:19 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void	ft_arg_validator(int argc, char *argv[], t_config *config)
{
	size_t	len;
	char	*str;

	if (argc == 1)
		ft_error_foo("You should pass at least one arg to Cub3D\n");
	str = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
	if (!str)
		ft_error_foo("invalid map format\n");
	len = ft_strlen(str);
	if (len != 4)
		ft_error_foo("invalid map format\n");
	if (argc == 3)
	{
		len = ft_strlen(argv[2]);
		if (len != 6 || ft_strnstr(argv[2], "--save", len) == NULL)
			ft_error_foo("As third arg expected cmd '--save'\n");
		else
			config->screenshot = 1;
	}
	if (argc > 3)
		ft_error_foo("Incorrect amount of parameters\n");
}
