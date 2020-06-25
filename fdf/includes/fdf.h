/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:37:26 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/25 18:59:40 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "../srcs/libft/includes/libft.h"

typedef struct		s_mlx
{
//	float			*x;
//	float 			*y;
	float 			**pxl;
	int 			x_max;
	int 			y_max;
	int 			fd;
}					t_mlx;

t_mlx 	*map_parsing(char **av);
int 	fdf_valid_malloc(t_mlx *mlx, char **av);

#endif
