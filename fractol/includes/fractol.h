/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:39 by bzmuda            #+#    #+#             */
/*   Updated: 2020/07/04 19:52:23 by lcassaun         ###   ########.fr       */
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
# define WIDTH			1600
# define HEIGHT 		900
# define KEY_ESC		53

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
	double			z_r;
	double			z_i;
	double			tmp;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			c_r;
	double			c_i;
	int				itmax;
	double			zoom;
	double			pr;
	double			pi;
}					t_fr;

void	fr_julia(t_fr *fr);
void	fr_create_mlx(t_fr *fr);
void	fr_mandelbrot(t_fr *fr);
void	bfr_pix(t_fr *fr);

#endif
