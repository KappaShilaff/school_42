/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:01:52 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/04 20:29:05 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		pix_to_img(t_fr *fr, int color)
{
	fr->color = (int)mlx_get_color_value(fr->mlx, color);
	ft_memmove(fr->img_str + (4 * (WIDTH * fr->y))
			   + (fr->x * 4), &fr->color, sizeof(int));
}

void			bfr_pix(t_fr *fr)
{
	if (fr->i == fr->itmax)
		pix_to_img(fr, 0);
	else
	{
		if (fr->fr_switch == 4)
			pix_to_img(fr, (fr->i * 90000));
		else
			pix_to_img(fr, (fr->i * 1100000));
	}
}
