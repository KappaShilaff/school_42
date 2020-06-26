/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:22:50 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/26 15:36:10 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int 	isometric(t_mlx *mlx)
{
	float	z1;
	float 	z2;

	z1 = (mlx->pxl)[(int)mlx->x1][(int)mlx->y1];
	z2 = (mlx->pxl)[(int)mlx->x2][(int)mlx->y2];
	mlx->x1 = (float)((mlx->x1 - mlx->y1) * cos(0.8));
	mlx->y1 = (float)((mlx->x1 + mlx->y1) * sin(0.8) - z1);
	mlx->x2 = (float)((mlx->x2 - mlx->y2) * cos(0.8));
	mlx->y2 = (float)((mlx->x1 + mlx->y1) * sin(0.8) - z2);
}

int 	draw_line(t_mlx *mlx)
{
	float 	x_step;
	float 	y_step;
	int 	max;

	isometric(mlx);
	x_step = mlx->x2 - mlx->x1;
	y_step = mlx->y2 - mlx->y1;
	if (x_step > y_step)
		max = (int)x_step;
	else
		max = (int)y_step;
	x_step /= (float)max;
	y_step /= (float)max;
	while ((int)(mlx->x2 - mlx->x1) || (int)(mlx->y2 - mlx->y1))
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (int)mlx->x1 * mlx->zoom, (int)mlx->y1 * mlx->zoom, 0xffffff);
		mlx->x1 += x_step;
		mlx->y1 += y_step;
	}
	return (0);
}

int 	draw(t_mlx *mlx)
{
	int 	x;
	int 	y;

	y = 0;
	mlx->zoom = 100;
	while (y < mlx->y_max)
	{
		x = 0;
		while(x < mlx->x_max)
		{
			mlx->x1 = (float)x;
			mlx->x2 = (float)x + 1;
			mlx->y1 = (float)y;
			mlx->y2 = (float)y + 1;
			draw_line(mlx);
			x++;
		}
		y++;
	}
	draw_line(mlx);
	return (0);
}
