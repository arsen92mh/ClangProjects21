/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:48:03 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/22 22:26:11 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/cub3d.h"

unsigned int	get_shot_color(t_data *img, int x, int i)
{
	int				offset;
	char			*dst;

	offset = i * img->l_l + x * (img->b_p_p / 8);
	dst = img->addr + offset;
	return (*(unsigned int *)dst);
}

void	ft_write_scrnshot(t_all *all, int fd)
{
	int				i;
	int				x;
	int				w;
	unsigned char	*buff;
	int				color;

	i = all->height - 1;
	w = all->width;
	buff = (unsigned char *)malloc(sizeof(unsigned char) * (w * 4));
	while (i >= 0)
	{
		x = 0;
		while (x < w)
		{
			color = get_shot_color(all->image, x, i);
			buff[x * 4] = (unsigned char)color;
			buff[x * 4 + 1] = (unsigned char)(color >> 8);
			buff[x * 4 + 2] = (unsigned char)(color >> 16);
			buff[x * 4 + 3] = (unsigned char)(color >> 24);
			x++;
		}
		write(fd, buff, all->width * 4);
		i--;
	}
	free(buff);
}

void	ft_header(t_all *all, int fd)
{
	unsigned char	header[54];
	int				i;

	ft_bzero(header, 54);
	header[0] = 'B';
	header[1] = 'M';
	i = 54 + 4 * all->height * all->width;
	header[2] = (unsigned char)i;
	header[3] = (unsigned char)(i >> 8);
	header[4] = (unsigned char)(i >> 16);
	header[5] = (unsigned char)(i >> 24);
	header[10] = 54;
	header[14] = 40;
	header[18] = (unsigned char)all->width;
	header[19] = (unsigned char)(all->width >> 8);
	header[20] = (unsigned char)(all->width >> 16);
	header[21] = (unsigned char)(all->width >> 24);
	header[22] = (unsigned char)all->height;
	header[23] = (unsigned char)(all->height >> 8);
	header[24] = (unsigned char)(all->height >> 16);
	header[25] = (unsigned char)(all->height >> 24);
	header[26] = 1;
	header[28] = 32;
	write(fd, header, 54);
}

void	save_screenshot(t_all *all)
{
	int				fd;

	fd = open("./screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (!fd)
		ft_error_foo("Can not create a screenshot\n");
	ft_header(all, fd);
	ft_write_scrnshot(all, fd);
	close(fd);
}
