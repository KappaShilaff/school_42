/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 02:17:49 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/30 20:25:53 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_color_switch(t_mlx *mlx, int *clr)
{
	if (mlx->clr_switch == 0)
		*clr = BLUE;
	if (mlx->clr_switch == 1)
		*clr = RED_FDF;
	if (mlx->clr_switch == 2)
		*clr = YELLOW;
	if (mlx->clr_switch == 3)
		*clr = WHITE;
	if (mlx->clr_switch == 4)
		*clr = GREEN;
}

void	fdf_color(t_mlx *mlx, float z1, float z2)
{
	int		z;
	int		clr;

	fdf_color_switch(mlx, &clr);
	if (z1 > z2)
		z = (int)z1;
	else
		z = (int)z2;
	if (mlx->clr_switch == 4)
		mlx->color = clr - (z * 3267);
	else if (mlx->clr_switch == 2)
		mlx->color = clr + (257 * z * 15);
	else
		mlx->color = clr - (257 * z * 15);
}
