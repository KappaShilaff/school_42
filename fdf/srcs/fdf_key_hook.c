/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 00:33:01 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/30 20:25:53 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_shift(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->shift_y -= (int)mlx->zoom;
	if (key == KEY_S)
		mlx->shift_y += (int)mlx->zoom;
	if (key == KEY_A)
		mlx->shift_x -= (int)mlx->zoom;
	if (key == KEY_D)
		mlx->shift_x += (int)mlx->zoom;
}

void	key_zoom(int key, t_mlx *mlx)
{
	if (key == KEY_UP && mlx->zoom > 2)
		mlx->zoom -= 2;
	if (key == KEY_DOWN)
		mlx->zoom += 2;
	if (key == KEY_RIGHT)
		mlx->zoom_z += (float)0.2;
	if (key == KEY_LEFT)
		mlx->zoom_z -= (float)0.2;
}

void	key_iso(int key, t_mlx *mlx)
{
	if (key == KEY_Q && mlx->x <= 0.9)
		mlx->x += 0.1;
	if (key == KEY_E && mlx->x >= -0.9)
		mlx->x -= 0.1;
	if (key == KEY_H)
		mlx->key_iso = (mlx->key_iso + 1) % 2;
}

int		key_hook(int key, t_mlx *mlx)
{
	if ((key >= 123 && key <= 126) || (key >= 12 && key <= 14)
		|| (key >= 0 && key <= 4) || key == 53)
	{
		key_shift(key, mlx);
		key_zoom(key, mlx);
		key_iso(key, mlx);
		if (key == KEY_F)
			mlx->clr_switch = (mlx->clr_switch + 1) % 5;
		if (key == KEY_ESC)
		{
			free_mlx(mlx);
			exit(EXIT_SUCCESS);
		}
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		draw(mlx, 0, 0);
	}
	return (1);
}
