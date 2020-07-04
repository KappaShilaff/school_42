/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:39 by bzmuda            #+#    #+#             */
/*   Updated: 2020/07/04 18:30:11 by lcassaun         ###   ########.fr       */
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

typedef struct		s_fr
{
	char 			*argv;
}					t_fr;

void	fr_julia(t_fr *fr);

#endif
