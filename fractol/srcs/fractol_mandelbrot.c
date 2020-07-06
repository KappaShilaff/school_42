/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:50:19 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/06 19:36:35 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void 	fr_shift(t_fr *fr)
{
	fr->x1 += (fr->shift_x / fr->zoom) / 10;
	fr->y1 += (fr->shift_y / fr->zoom) / 10;
	fr->shift_x_sum += fr->shift_x;
	fr->shift_y_sum += fr->shift_y;
}

static void	fr_fill_mandel(t_fr *fr, int i)
{
	fr->x = 0;
	fr->y = 0;
	fr->i = 0;
	fr->x1 = -5.5;
	fr->y1 = -3.25;
	fr->itmax = 40;
	fr->zoom = 150;
	fr->fr_switch = 2;
	fr->thread = i;
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

void 		fr_mandelbrot_draw_thread(t_fr *fr)
{
	fr->y = fr->thread;
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
		fr->y += 3;
		fr->x = 0;
	}
	fr->x = 0;
	fr->y = 0;
}

void		fr_mandelbrot_draw(t_fr **fr)
{
	pthread_create(&(fr[0]->thread_id[0]), NULL, (void *)fr_mandelbrot_draw_thread, fr[0]);
	pthread_create(&(fr[0]->thread_id[1]), NULL, (void *)fr_mandelbrot_draw_thread, fr[1]);
	pthread_create(&(fr[0]->thread_id[2]), NULL, (void *)fr_mandelbrot_draw_thread, fr[2]);
	pthread_join(fr[0]->thread_id[0], NULL);
	pthread_join(fr[0]->thread_id[1], NULL);
	pthread_join(fr[0]->thread_id[2], NULL);
	mlx_put_image_to_window(fr[0]->mlx, fr[0]->win, fr[0]->img, 0, 0);
	mlx_loop(fr[0]->mlx);
}

void 		fr_fill_another(t_fr **fr)
{
	printf("1\n");
	fr[1]->mlx = fr[0]->mlx;
	printf("2\n");
	fr[1]->win = fr[0]->win;
	printf("3\n");
	fr[1]->img = fr[0]->img;
	printf("4\n");
	fr[1]->img_str = fr[0]->img_str;
	printf("5\n");
	fr[2]->mlx = fr[0]->mlx;
	printf("6\n");
	fr[2]->win = fr[0]->win;
	printf("7\n");
	fr[2]->img = fr[0]->img;
	printf("8\n");
	fr[2]->img_str = fr[0]->img_str;
	printf("9\n");
}

void		fr_mandelbrot(t_fr **fr)
{
	fr_create_mlx(fr);
	fr_fill_another(fr);
	fr_fill_mandel(fr[0], 0);
	fr_fill_mandel(fr[1], 1);
	fr_fill_mandel(fr[2], 2);
	fr_mandelbrot_draw(fr);
}
