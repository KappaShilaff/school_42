/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:01:52 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/06 17:12:09 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		fr_pix_to_img(t_fr *fr, int color)
{
	fr->color = (int)mlx_get_color_value(fr->mlx, color);
	if (fr->y > 0 && fr->y < HEIGHT && fr->x < WIDTH && fr->x > 0)
	ft_memmove(fr->img_str + (4 * (WIDTH * fr->y))
			   + (fr->x * 4), &fr->color, sizeof(int));
}

void			fr_bfr_pix(t_fr *fr)
{
	if (fr->i == fr->itmax)
		fr_pix_to_img(fr, 0);
	else
		fr_pix_to_img(fr, (fr->i * 1100000));
}

void	fr_draw(t_fr *fr)
{
	if (fr->fr_switch == 2)
		fr_mandelbrot_draw(fr);
}

void	fr_zoom(t_fr *fr, int x, int y)
{
	double x_n;
	double y_n;

	if (y > 0 && x > 0)
	{
		x_n = (x / fr->zoom) + fr->x1;
		y_n = (y / fr->zoom) + fr->y1;
		fr->zoom *= 1.35;
		fr->x1 = x_n - (x / fr->zoom);
		fr->y1 = y_n - (y / fr->zoom);
		fr_draw(fr);
	}
}

void	fr_dezoom(t_fr *fr, int x, int y)
{
	double x_n;
	double y_n;

	x_n = (x / fr->zoom) + fr->x1;
	y_n = (y / fr->zoom) + fr->y1;
	fr->zoom /= 1.35;
	fr->x1 = x_n - (x / fr->zoom);
	fr->y1 = y_n - (y / fr->zoom);
	fr_draw(fr);
}
