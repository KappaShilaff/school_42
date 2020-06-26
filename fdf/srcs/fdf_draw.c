/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:22:50 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/26 15:15:43 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int 	draw_line(t_mlx *mlx)
{
	float 	x_step;
	float 	y_step;
	int 	max;

	x_step = mlx->x1 - mlx->x2;
	y_step = mlx->y1 - mlx->y2;
	if (x_step > y_step)
		max = (int)x_step;
	else
		max = (int)y_step;
	x_step /= (float)max;
	y_step /= (float)max;
	while ((int)(mlx->x1 - mlx->x2) || (int)(mlx->y2 - mlx->y1))
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x1, mlx->y1, 0xffffff);
		mlx->x1 += x_step;
		mlx->y1 += y_step;
	}
	return (0);
}

int 	draw(t_mlx *mlx)
{
	mlx->x1 = 100;
	mlx->x2 = 157;
	mlx->y1 = 130;
	mlx->y2 = 30;
	draw_line(mlx);
	return (0);
}
