/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kulrike <kulrike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:29:23 by kulrike           #+#    #+#             */
/*   Updated: 2020/12/28 14:24:51 by kulrike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_p_t
{
	char		type;
	int			length;
	int			format_length;
	int			zero_flag;
	int			minus_flag;
	int			precision;
	int			precision_indicator;
	int			width;
	int			sxt_len;
	int			error;
	int			space;
}				t_p_t;

int				ft_printf(const char *str, ...);
int				ft_atoi(char *c);
int				ft_strlen(const char *s);
void			int_processor_d_i(t_p_t *options, va_list argptr);
void			ft_uint_putnbr_fd(unsigned int n, t_p_t *options);
void			ft_write(char c, t_p_t *options);
void			ft_putnbr_fd(int n, t_p_t *options);
void			str_processor(t_p_t *options, va_list argptr);
void			char_processor(t_p_t *options, va_list argptr);
void			uint_processor(t_p_t *options, va_list argptr);
void			sixteen_processor(t_p_t *options, va_list argptr);
void			ft_sxt_putnbr_fd(unsigned int d, t_p_t *options, char type);
void			ptr_processor(t_p_t *options, va_list argptr);
void			percent_processor(t_p_t *options, va_list argptr);
void			ft_ptr_putnbr(unsigned long long n, t_p_t *options);
void			ft_ull_putnbr_fd(unsigned long long n, t_p_t *options);
void			main_parser(const char *str, t_p_t *options, va_list *argptr);
void			start_process(t_p_t *options, va_list argptr);

#endif
