/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_create_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:57:48 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/05 17:05:58 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fr_create_mlx(t_fr *fr)
{
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, WIDTH, HEIGHT, "Fractol");
	fr->img = mlx_new_image(fr->mlx, WIDTH, HEIGHT);
	fr->img_str = mlx_get_data_addr(fr->img, &fr->bpp, &fr->strlen, &fr->endian);
	mlx_mouse_hook(fr->win, fr_mouse, fr);
	mlx_key_hook(fr->win, fr_key, fr);
	fr->shift_y = 0;
	fr->shift_x = 0;
	fr->shift_x_sum = 0;
	fr->shift_y_sum = 0;
}
