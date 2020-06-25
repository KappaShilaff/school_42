/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:23:10 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/25 21:41:48 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//int 	incase(t_mlx *mlx, const char *line)
//{
//	int 	i;
//
//	i = 0;
//	while (line[i] && (line[i] >= '0' && line[i] <= '9' || line[i] == ' '))
//		i++;
//	if (line[i])
//		return (0);
//	i = 0;
//	while (line[i] && (line[i] >= '0' && line[i] <= '9' || line[i] == ' '))
//	{
//		if (line[i] >= '0' && line[i] <= '9')
//			incase_xyz(mlx, ft_atoi(&line[i]));
//		i++;
//	}
//	return (1);
//}

float 	**fdf_split(t_mlx *mlx, char **av)
{
	float	**temp;
	char 	**nbr;
	char 	*line;
	int 	y;
	int 	x;

	y = 0;
	temp = malloc(sizeof(float *) * mlx->y_max);
	mlx->fd = open(av[1], O_RDONLY);
		while (get_next_line(mlx->fd, &line) > 0 && y < mlx->y_max)
	{
		nbr = ft_strsplit(line, ' ');
		free(line);
		x = 0;
		temp[y] = malloc(sizeof(float) * mlx->x_max);
		while (x < mlx->x_max)
		{
			temp[y][x] = (float)ft_atoi(nbr[x]);
			free(nbr[x++]);
		}
		free(nbr);
		y++;
	}
	return (temp);
}

t_mlx 	*map_parsing(char **av)
{
	t_mlx	*mlx;
	char 	*line;

	if (!(mlx = malloc(sizeof(t_mlx))))
	{
		return (0);
	}
	mlx->fd = open(av[1], O_RDONLY);
	if (fdf_valid_malloc(mlx, av) == 0)
	{
		close(mlx->fd);
		free(mlx);
		return (NULL);
	}
	close(mlx->fd);
	mlx->pxl = fdf_split(mlx, av);
	return (mlx);
}