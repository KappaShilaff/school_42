/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:01:52 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/08 17:20:24 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		fr_pix_to_img(t_fr *fr)
{
//	fr->color = (int)mlx_get_color_value(fr->mlx, (int)fr->color_temp);
	if (fr->y > 0 && fr->y < HEIGHT && fr->x < WIDTH - fr->menu && fr->x > 0)
	ft_memmove(fr->img_str + (4 * ((WIDTH - fr->menu) * fr->y))
			   + (fr->x * 4), &fr->color_temp, sizeof(int));
}

//void 	fr_color(t_fr *fr)
//{
//	fr->color_temp = (float)fr->i / (float)fr->itmax * fr->rgb2;
//	fr->color_temp1 = fr->rgb1 * fr->rgb1 * fr->rgb1;
//	fr->color_temp = fr->color_temp * fr->color_temp * fr->color_temp + fr->color_temp1;
//}
void 	fr_color(t_fr *fr)
{
//	fr->color_temp = 0x0000ff;
//	fr->rgb1 = 0x010000;
//	fr->rgb2 = 0x000100;
	fr->color_temp = 0x5faf5f - 0x010000 * (0x5f * fr->i / fr->itmax) - 0x000001 * (0x5f * fr->i / fr->itmax);
}

void			fr_bfr_pix(t_fr *fr)
{
	if (fr->i == fr->itmax)
	{
		fr->color_temp = 0;
		fr_pix_to_img(fr);
	}
	else
	{
		fr_color(fr);
		fr_pix_to_img(fr);
	}
}

void	fr_draw(t_fr **fr)
{
	if (fr[0]->fr_switch == 1)
		fr_julia_draw(fr);
	if (fr[0]->fr_switch == 2)
		fr_mandelbrot_draw(fr);
	if (fr[0]->fr_switch == 3)
		fr_chameleon_draw(fr);
	if (fr[0]->fr_switch == 4)
		fr_ship_draw(fr);
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
}
