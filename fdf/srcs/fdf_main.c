/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:36:37 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/25 19:01:42 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
int main(int ac, char **argv)
{
	t_mlx	*mlx;

	mlx = map_parsing(argv);
	if (mlx == NULL)
		ft_putstr("invalid otstrelen\n");
	else
	{
		printf("x = %d\ny = %d", mlx->x_max, mlx->y_max);
		free(mlx);
	}
	return (0);
}