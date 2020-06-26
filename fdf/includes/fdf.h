/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:37:26 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/26 14:42:23 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# define WIDTH		1600
# define HEIGHT		900
# define MENU		250
# include "../srcs/libft/includes/libft.h"
# include "mlx.h"

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
}					t_mlx;

t_mlx 	*map_parsing(char **av);
int 	fdf_valid_malloc(t_mlx *mlx, char **av);
int 	draw(t_mlx *mlx);

#endif
