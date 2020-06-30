/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:11:17 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/30 15:30:55 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	drow_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		30, 80, 0xffffff, "key_shift        - w a s d");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		30, 130, 0xffffff, "key_zoom         - up down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		30, 180, 0xffffff, "key_zoom_z       - left right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		30, 230, 0xffffff, "key_rotation     - q e");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		30, 280, 0xffffff, "key_change_color - f");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		30, 320, 0xffffff, "exit             - esc");
}
