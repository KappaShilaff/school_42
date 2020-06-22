/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:55:01 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/23 00:21:20 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <unistd.h>

int 	deal_key()
{
	write(1, "X", 1);
	return (0);
}

int 	main(void)
{
	void	*mlx_ptr;
	void 	*win_ptr;



	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 215);
	mlx_string_put(mlx_ptr, win_ptr, 200, 200, 215, "lol");
	mlx_key_hook(win_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
}