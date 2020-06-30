/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:11:17 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/30 21:21:46 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	drow_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIDTH - 330, 30, 0xffffff, "key_shift        - w a s d");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIDTH - 330, 60, 0xffffff, "key_zoom         - up down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIDTH - 330, 90, 0xffffff, "key_zoom_z       - left right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIDTH - 330, 120, 0xffffff, "key_rotation     - q e");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIDTH - 330, 150, 0xffffff, "key_change_color - f");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIDTH - 330, 180, 0xffffff, "key_projection   - h");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		WIDTH - 330, 210, 0xffffff, "key_exit         - esc");
}
