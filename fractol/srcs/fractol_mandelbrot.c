/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:50:19 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/05 17:27:20 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void 	fr_shift(t_fr *fr)
{
	fr->x1 += (fr->shift_x / fr->zoom) / 10;
	fr->y1 += (fr->shift_y / fr->zoom) / 10;
	fr->x2 += (fr->shift_x / fr->zoom) / 10;
	fr->y2 += (fr->shift_y / fr->zoom) / 10;
}

static void	fr_fill_mandel(t_fr *fr)
{
	fr->x = 0;
	fr->y = 0;
	fr->i = 0;
	fr->x1 = -5.5;
	fr->x2 = 2.5;
	fr->itmax = 40;
	fr->zoom = 150;
	fr->fr_switch = 2;
}

static void	fr_calc_mandel(t_fr *fr)
{
	while (fr->z_r * fr->z_r + fr->z_i * fr->z_i < 4 && fr->i < fr->itmax)
	{
		fr->tmp = fr->z_r;
		fr->z_r = fr->z_r * fr->z_r - fr->z_i * fr->z_i + fr->c_r;
		fr->z_i = 2 * fr->z_i * fr->tmp + fr->c_i;
		fr->i++;
	}
}

void		fr_mandelbrot_draw(t_fr *fr)
{
	fr_shift(fr);
	while (fr->y < HEIGHT)
	{
		while (fr->x < WIDTH)
		{
			fr->c_r = fr->x / fr->zoom + fr->x1;
			fr->c_i = fr->y / fr->zoom + fr->y1;
			fr->z_r = 0;
			fr->z_i = 0;
			fr_calc_mandel(fr);
			fr_bfr_pix(fr);
			fr->i = 0;
			fr->x++;
		}
		fr->y++;
		fr->x = 0;
	}
	fr->x = 0;
	fr->y = 0;
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_loop(fr->mlx);
}

void		fr_mandelbrot(t_fr *fr)
{
	fr_create_mlx(fr);
	fr_fill_mandel(fr);
	fr_mandelbrot_draw(fr);
}
