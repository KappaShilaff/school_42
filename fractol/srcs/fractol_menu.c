/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:24:29 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/07 23:36:50 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fr_draw_menu(t_fr **fr)
{
	mlx_string_put(fr[0]->mlx, fr[0]->mlx,
				   WIDTH - 330, 30, 0xffffff, "key_shift  - w a s d");
	mlx_string_put(fr[0]->mlx, fr[0]->mlx,
				   WIDTH - 330, 60, 0xffffff, "key_zoom   - mouse scroll");
	mlx_string_put(fr[0]->mlx, fr[0]->mlx,
				   WIDTH - 330, 210, 0xffffff, "key_exit   - esc");
}
