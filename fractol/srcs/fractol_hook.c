/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mouse_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:25:47 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/05 17:18:29 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fr_key_shift(int key, t_fr *fr)
{
	if (key == KEY_W)
	{
		fr->shift_y = fr->zoom / 150;
		fr->shift_x = 0;
	}
	if (key == KEY_S)
	{
		fr->shift_y = -fr->zoom / 150;
		fr->shift_x = 0;
	}
	if (key == KEY_A)
	{
		fr->shift_x = -fr->zoom / 150;
		fr->shift_y = 0;
	}
	if (key == KEY_D)
	{
		fr->shift_x = fr->zoom / 150;
		fr->shift_y = 0;
	}
}

int		fr_mouse(int code, int x, int y, t_fr *fr)
{
	if (code == 4 || code == 1)
	{
		fr_zoom(fr, x, y);
		fr_draw(fr);
	}
	else if (code == 5 || code == 2)
	{
		fr_dezoom(fr, x, y);
		fr_draw(fr);
	}
	return (0);
}

int		fr_key(int key, t_fr *fr)
{
	if (key == KEY_ESC)
	{
		free(fr);
		exit(EXIT_SUCCESS);
	}
	if ((key >= 0 && key <= 2) || key == 13)
	{
		fr_key_shift(key, fr);
		fr_draw(fr);
	}
	return (0);
}
