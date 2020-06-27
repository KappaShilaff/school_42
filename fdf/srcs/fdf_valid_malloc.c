/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_valid_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:59:51 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/28 01:20:37 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		free_line(char **line)
{
	free(*line);
	return (0);
}

int		map_x(const char *av)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while ((av[i] && av[i] >= '0' && av[i] <= '9') ||
	(av[i] == '-' || av[i] == ' '))
	{
		if ((av[i] >= '0' && av[i] <= '9') || av[i] == '-')
		{
			x++;
			while ((av[i] && av[i] >= '0' && av[i] <= '9') || av[i] == '-')
				i++;
			if (av[i] && av[i] != ' ')
				return (0);
			i--;
		}
		i++;
	}
	if (av[i])
		return (0);
	return (x);
}

int		fdf_valid_malloc(t_mlx *mlx)
{
	char	*line;

	mlx->y_max = 0;
	mlx->x_max = 0;
	while (get_next_line(mlx->fd, &line) > 0)
	{
		(mlx->y_max)++;
		if (mlx->x_max == 0)
			if ((mlx->x_max = map_x(line)) == 0)
				return (free_line(&line));
		if (mlx->x_max != map_x(line))
			return (free_line(&line));
		free(line);
	}
	return (1);
}
