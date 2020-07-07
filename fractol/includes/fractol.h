/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:39 by bzmuda            #+#    #+#             */
/*   Updated: 2020/07/07 15:30:43 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../srcs/libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <pthread.h>
# define WIDTH			1600
# define HEIGHT 		900
# define KEY_ESC		53
# define KEY_W 			13
# define KEY_S 			1
# define KEY_A 			0
# define KEY_D 			2



typedef struct		s_fr
{
	char 			*argv;
	void			*mlx;
	void			*win;
	void 			*img;
	char			*img_str;
	int				endian;
	int				strlen;
	int				bpp;
	int 			fr_switch;
	int				x;
	int				y;
	int				i;
	int				color;
	int				s_l;
	long double			z_r;
	long double			z_i;
	long double			tmp;
	long double			x1;
	long double			y1;
	long double			x2;
	long double			y2;
	long double			c_r;
	long double			c_i;
	int				itmax;
	long double			zoom;
	long double			pr;
	long double			pi;
	long double 			shift_x;
	long double 			shift_y;
	pthread_t 		*thread_id;
	int 			thread;
}					t_fr;

void	fr_julia(t_fr *fr);
void	fr_create_mlx(t_fr **fr);
void	fr_mandelbrot(t_fr **fr);
void	fr_bfr_pix(t_fr *fr);
void 	fr_mandelbrot_draw(t_fr **fr);
void	fr_draw(t_fr **fr);
void	fr_zoom(t_fr *fr, int x, int y);
void	fr_dezoom(t_fr *fr, int x, int y);
int		fr_mouse(int code, int x, int y, t_fr **fr);
int		fr_key(int code, t_fr **fr);
void	fr_shift(t_fr *fr);
void	fr_fill_another(t_fr **fr);
void	fr_chameleon(t_fr **fr);
void	fr_chameleon_draw(t_fr **fr);

#endif
