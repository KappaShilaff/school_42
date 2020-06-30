/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:36:37 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/30 20:25:53 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <errno.h>

int		free_mlx(t_mlx *mlx)
{
	while ((mlx->y_max)-- != 0)
		free((mlx->pxl)[mlx->y_max]);
	free(mlx->pxl);
	close(mlx->fd);
	free(mlx);
	return (0);
}

int		main(int ac, char **argv)
{
	t_mlx	*mlx;

	mlx = map_parsing(argv);
	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n", 2);
		return (0);
	}
	if (mlx == NULL)
		return (0);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "fdf");
	mlx->shift_x = 100;
	mlx->shift_y = 100;
	mlx->key_iso = 1;
	mlx->zoom_z = (float)0.2;
	mlx->x = 0.8;
	mlx->zoom = 10;
	draw(mlx, 0, 0);
	mlx_key_hook(mlx->win_ptr, key_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
