/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:36:37 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/25 21:40:49 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int 	free_mlx(t_mlx *mlx)
{
	while ((mlx->y_max)-- != 0)
		free((mlx->pxl)[mlx->y_max]);
	free(mlx->pxl);
	close(mlx->fd);
	free(mlx);
	return (0);
}

int main(int ac, char **argv)
{
	t_mlx	*mlx;
	int 	temp_x;
	int 	temp_y;

	mlx = map_parsing(argv);
	if (mlx == NULL)
	{
		ft_putstr("invalid otstrelen\n");
		return (0);
	}
	printf("x = %d\ny = %d\n", mlx->x_max, mlx->y_max);
	temp_x = mlx->x_max;
	temp_y = mlx->y_max;
	while ((mlx->y_max)-- != 1)
	{
		mlx->x_max = temp_x;
		while ((mlx->x_max-- != 1))
			printf("%2.0f ", (mlx->pxl)[temp_y - mlx->y_max][temp_x - mlx->x_max]);
		printf("\n");
	}
	mlx->x_max = temp_x;
	mlx->y_max = temp_y;
	free_mlx(mlx);
	return (0);
}