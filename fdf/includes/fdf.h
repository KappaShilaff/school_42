/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:37:26 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/28 00:26:16 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# define WIDTH		1600
# define HEIGHT		900
# define KEY_UP			125
# define KEY_DOWN		126
# define KEY_RIGHT		124
# define KEY_LEFT		123
# define KEY_ESC		53
# define KEY_E 			14
# define KEY_Q 			12
# define KEY_W 			13
# define KEY_S 			1
# define KEY_A 			0
# define KEY_D 			2

# include "../srcs/libft/includes/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct		s_mlx
{
	float			x1;
	float 			y1;
	float 			x2;
	float 			y2;
	void 			*mlx_ptr;
	void 			*win_ptr;
	float 			**pxl;
	int 			x_max;
	int 			y_max;
	int 			fd;
	float 			zoom;
	int 			color;
	int 			shift_x;
	int 			shift_y;
	double 			x;
	float 			zoom_z;
}					t_mlx;

t_mlx 	*map_parsing(char **av);
int 	fdf_valid_malloc(t_mlx *mlx, char **av);
int 	draw(t_mlx *mlx);
int 	free_mlx(t_mlx *mlx);
int 	key_hook(int key, t_mlx *mlx);

#endif
