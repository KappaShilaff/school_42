/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:22:50 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/27 09:00:46 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float 	float_abs(float x)
{
	return (x < 0 ? -x : x);
}

int 	isometric(t_mlx *mlx, float z1, float z2)
{
	mlx->x1 = (float)((mlx->x1 - mlx->y1) * cos(0.8));
	mlx->y1 = (float)((mlx->x1 + mlx->y1) * sin(0.8) - z1);
	mlx->x2 = (float)((mlx->x2 - mlx->y2) * cos(0.8));
	mlx->y2 = (float)((mlx->x2 + mlx->y2) * sin(0.8) - z2);
}

int 	draw_line(t_mlx *mlx)
{
	float 	x_step;
	float 	y_step;
	float	z1;
	float 	z2;
	int 	max;

	z1 = (mlx->pxl)[(int)mlx->y1][(int)mlx->x1];
	z2 = (mlx->pxl)[(int)mlx->y2][(int)mlx->x2];
	mlx->color = (z1 || z2) ? 0xe80c0c : 0xffffff;
 	mlx->x1 *= (float)mlx->zoom;
	mlx->x2 *= (float)mlx->zoom;
	mlx->y1 *= (float)mlx->zoom;
	mlx->y2 *= (float)mlx->zoom;
	isometric(mlx, z1, z2);
	mlx->x1 += (float)mlx->shift_x;
	mlx->x2 += (float)mlx->shift_x;
	mlx->y1 += (float)mlx->shift_y;
	mlx->y2 += (float)mlx->shift_y;
	x_step = mlx->x2 - mlx->x1;
	y_step = mlx->y2 - mlx->y1;
	if (float_abs(x_step) > float_abs(y_step))
		max = (int)float_abs(x_step);
	else
		max = (int)float_abs(y_step);
	x_step /= (float)max;
	y_step /= (float)max;
	while ((int)(mlx->x1 - mlx->x2) || (int)(mlx->y1 - mlx->y2))
	{
		if (mlx->x1 > 0 && mlx->y1 > 0 && ((int)mlx->x1 < WIDTH) && (int)mlx->y1 < HEIGHT)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (int)mlx->x1, (int)mlx->y1, mlx->color);
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
	while (y < mlx->y_max)
	{
		x = 0;
		while(x < mlx->x_max)
		{
			if (x < mlx->x_max - 1)
			{
				mlx->x1 = (float)x;
				mlx->x2 = ((float)x + 1);
				mlx->y1 = (float)y;
				mlx->y2 = ((float)y);
				draw_line(mlx);
			}
			if (y < mlx->y_max - 1)
			{
				mlx->x1 = (float)x;
				mlx->x2 = ((float)x);
				mlx->y1 = (float)y;
				mlx->y2 = ((float)y + 1);
				draw_line(mlx);
			}
			x++;
		}
		y++;
	}
	return (0);
}
