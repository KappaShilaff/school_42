/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:36:37 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/27 17:23:56 by lcassaun         ###   ########.fr       */
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

int 	key_hook(int key, t_mlx *mlx)
{
	if ((key >= 123 && key <= 126) || (key >= 12 && key <= 14)
	|| (key >= 0 && key <= 2) || key == 53)
	{
		if (key == KEY_S)
			mlx->shift_y -= mlx->zoom;
		if (key == KEY_W)
			mlx->shift_y += mlx->zoom;
		if (key == KEY_A)
			mlx->shift_x -= mlx->zoom;
		if (key == KEY_D)
			mlx->shift_x += mlx->zoom;
		if (key == KEY_ESC)
		{
			free_mlx(mlx);
			exit(EXIT_SUCCESS);
		}
		if (key == KEY_UP && mlx->zoom > 2)
			mlx->zoom -= 2;
		if (key == KEY_DOWN)
			mlx->zoom += 2;
		if (key == KEY_Q && mlx->x <= 0.9)
			mlx->x += 0.1;
		if (key == KEY_E && mlx->x >= -0.9)
			mlx->x -= 0.1;
		if (key == KEY_RIGHT)
			mlx->zoom_z += 2;
		if (key == KEY_LEFT && mlx->zoom_z > 2)
			mlx->zoom_z -= 2;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		draw(mlx);
	}
	return (1);
}

int main(int ac, char **argv)
{
	t_mlx	*mlx;
//	int 	temp_x;
//	int 	temp_y;

	mlx = map_parsing(argv);
	if (mlx == NULL)
	{
		ft_putstr("invalid otstrelen\n");
		return (0);
	}
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "fdf");
	mlx->shift_x = 100;
	mlx->shift_y = 100;
	mlx->zoom_z = 2;
	mlx->x = 0.8;
	mlx->zoom = 10;
	draw(mlx);
	mlx_key_hook(mlx->win_ptr, key_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
//	printf("x = %d\ny = %d\n", mlx->x_max, mlx->y_max);
//	temp_x = mlx->x_max;
//	temp_y = mlx->y_max;
//	while ((mlx->y_max)-- != 1)
//	{
//		mlx->x_max = temp_x;
//		while ((mlx->x_max-- != 1))
//			printf("%3.0f ", (mlx->pxl)[temp_y - mlx->y_max][temp_x - mlx->x_max]);
//		printf("\n");
//	}
//	mlx->x_max = temp_x;
//	mlx->y_max = temp_y;
//	free_mlx(mlx);
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xffffff);
//	mlx_string_put(mlx_ptr, win_ptr, 100, 100, 0xffffff, "lol");
	return (0);
}