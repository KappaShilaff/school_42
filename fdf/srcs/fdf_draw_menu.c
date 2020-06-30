/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:11:17 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/30 15:16:38 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	drow_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			30, 30, 0xffffff, "key_shift        - w a s d\n"
	"key_zoom         - up down\n"
	"key_zoom_z       - left right\n"
	"key_rotation     - q e\n"
	"key_change_color - f\n"
	"exit             - esc");
}
