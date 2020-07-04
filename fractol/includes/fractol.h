/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:39 by bzmuda            #+#    #+#             */
/*   Updated: 2020/07/04 19:02:16 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../srcs/libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>
# define WIDTH	1600
# define HEIGHT 900

typedef struct		s_fr
{
	char 			*argv;
	void			*mlx;
	void			*win;
	void 			*img;
	char			*img_str;
	int				endian;
	int				strlen;
	int				bpp;
}					t_fr;

void	fr_julia(t_fr *fr);
void	fr_create_mlx(t_fr *fr);

#endif
