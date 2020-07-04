/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_create_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:57:48 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/04 19:03:28 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fr_create_mlx(t_fr *fr)
{
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, HEIGHT, WIDTH, "Fractol");
	fr->img = mlx_new_image(fr->mlx, HEIGHT, WIDTH);
	fr->img_str = mlx_get_data_addr(fr->img, &fr->bpp, &fr->strlen, &fr->endian);
}
