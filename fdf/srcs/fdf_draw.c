/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:22:50 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/26 14:45:49 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int 	draw(void *mlx_ptr, void *win_ptr, t_mlx *mlx)
{
	float 	x;
	float 	x1;
	float 	y;
	float 	y1;
	float 	max;
	float 	max_temp;
	float 	step_x;
	float 	step_y;

	x = 10;
	x1 = 50;
	y = 20;
	y1 = 100;
	max = ft_abs((long)(x - x1));
	max_temp = ft_abs((long)(y - y1));
	if (max_temp > max)
		max = max_temp;
	step_x = (x1 - x) / max;
	step_y = (y1 - y) / max;
	while((int)(x1 - x) > 0 || (int)(y1 - y) > 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, oxffffff);
		x += step_x;
		y += step_y;
	}
}
