/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:42:54 by kulrike           #+#    #+#             */
/*   Updated: 2021/04/25 17:04:10 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../Libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include "mlx.h"
# include <math.h>
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct s_config
{
	int			width;
	int			height;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			floor[3];
	int			ceiling[3];
	int			config_complete;
	int			map_start;
	int			error;
	int			sprites;
	int			screenshot;

}				t_config;

typedef struct s_list	t_list;

struct			s_list
{
	char		*map;
	t_list		*next;
	t_list		*prev;
};

typedef struct s_sprcast
{
	int			num;
	int			dist;
	double		spr_x;
	double		spr_y;
	double		inv_det;
	double		tr_x;
	double		tr_y;
	int			spr_scr_x;
	int			vmv_scr;
	int			spr_hght;
	int			dr_st_y;
	int			dr_en_y;
	int			spr_w;
	int			dr_st_x;
	int			dr_en_x;
	int			stripe;
	int			texx;
	int			y;
	int			d;
	int			texy;
	int			*order;
	double		*distance;
}				t_sprcast;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			img_width;
	int			img_height;
	int			bpp;
	int			l_length;
	int			endian;
}				t_image;

typedef struct s_sprite
{
	double		x;
	double		y;
}				t_sprite;
typedef struct s_data {
	void		*img;
	char		*addr;
	int			b_p_p;
	int			l_l;
	int			endian;
}				t_data;

typedef struct s_player
{
	double		plr_x;
	double		plr_y;
	double		dir;
	int			map;
	double		dir_x;
	double		dir_y;
	double		pln_x;
	double		pln_y;
}				t_player;

typedef struct s_dda
{
	double		camera_x;
	double		r_dir_x;
	double		r_dir_y;
	double		s_dist_x;
	double		s_dist_y;
	double		d_dist_x;
	double		d_dist_y;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			hit;
	int			side;
}				t_dda;

typedef struct s_d_prm
{
	int			l_hght;
	int			draw_st;
	int			draw_e;
	double		wall_x;
	int			texx;
	double		step;
	double		tex_pos;
}				t_d_prm;

typedef struct s_casting
{
	t_dda		*dda;
	t_d_prm		*tdp;
}				t_casting;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_data		*image;
	int			c_clr;
	int			f_clr;
	float		fov;
	int			height_center;
	int			width_center;
	t_image		*north;
	t_image		*south;
	t_image		*east;
	t_image		*west;
	t_image		*sprite;
	int			width;
	int			height;
	float		dist_to_pp;
	char		**map;
	int			sprite_amount;
	int			screenshot;
	t_sprite	**sprites;
}				t_all;

typedef struct s_map
{
	int			map_x;
}				t_map;

void			ft_arg_validator(int argc, char	*argv[], t_config *config);
t_player		*ft_init_player(void);
t_list			*ft_start_init(void);
void			ft_set_config_null(t_config *config);
int				get_next_line(int fd, char **line);
void			ft_main_parser(char **line, t_config *config, t_list *start);
void			ft_screen_resolution(const char *line, t_config *config);
int				ft_error_foo(char *str);
size_t			ft_shift(int a);
void			ft_config_management(const char *line, t_config *config);
void			ft_map_line_vd(t_list *tmp, t_player *player, t_config *config);
void			ft_cub_start(t_config *config, char **map, t_player *player);
void			ft_player(int x, int i, t_player *player, char orient);
void			ft_nullchar_check_2(t_list *start, int i);
void			ft_nullchar_check(t_list *start, int i);
void			save_screenshot(t_all *all);
t_all			*ft_init_all(t_config *conf, t_player *player, char **map);
t_sprite		**ft_get_sprite_coords(t_all *all);
void			ft_screen(t_all *all, t_config *config);
void			ft_draw_all_(t_all *all);
void			my_mlx_pix_put(t_data *data, int y, int x, unsigned long c);
unsigned long	get_color(t_image *data, int texx, int texy);
void			ft_draw(t_casting *cast, t_all *all, int x, t_image *texture);
void			ft_draw_sprites(t_all *all, double *dist_buffer);
double			ft_pependicular_dist(int w, t_dda *dda, t_all *all);
t_casting		*ft_ret_cast(void);
t_sprcast		*ft_init_spr(t_all *all);
void			ft_spr_calc_1(t_sprcast *spr, t_all *all, int x);
void			ft_floor_ceiling(const char *c, int *to_fill, t_config *config);
int				ft_big_int_check(const char *str);
int				ret_num(const char *line);
size_t			ft_get_num_len(const char *str);

#endif
