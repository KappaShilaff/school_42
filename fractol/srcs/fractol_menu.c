/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:24:29 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/08 01:21:12 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fr_draw_menu(t_fr **fr)
{
	if (fr[0]->menu == 340)
	{
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 30, 0xffffff, "Julia        - 1");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 90, 0xffffff, "Burning ship - 2");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 120, 0xffffff, "Chameleon    - 3");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 150, 0xffffff, "Mandelbrot   - 4");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 180, 0xffffff, "Shift        - w a s d");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 210, 0xffffff, "Zoom         - mouse scroll");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 240, 0xffffff, "       or left/right button");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 270, 0xffffff, "Hide menu    - f");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
					   WIDTH - 330, 300, 0xffffff, "Exit         - esc");
		if(fr[0]->fr_switch == 1)
		{
			mlx_string_put(fr[0]->mlx, fr[0]->win,
						   WIDTH - 330, 330, 0xffffff,
						   "Julia hook  - mouse scroll");
		}
	}
}
