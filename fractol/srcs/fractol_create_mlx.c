/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_create_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:57:48 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/07 23:32:28 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fr_create_mlx(t_fr **fr)
{
	fr[0]->mlx = mlx_init();
	fr[0]->win = mlx_new_window(fr[0]->mlx, WIDTH, HEIGHT, "Fractol");
	fr[0]->img = mlx_new_image(fr[0]->mlx, WIDTH, HEIGHT);
	fr[0]->img_str = mlx_get_data_addr(fr[0]->img, &fr[0]->bpp, &fr[0]->strlen, &fr[0]->endian);
	mlx_mouse_hook(fr[0]->win, fr_mouse, fr);
	mlx_key_hook(fr[0]->win, fr_key, fr);
	fr[0]->shift_y = 0;
	fr[0]->shift_x = 0;
}
