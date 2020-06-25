/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:23:10 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/25 18:59:40 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int 	incase_malloc(t_mlx *mlx, const char *line)
{

}

int 	incase_xyz(t_mlx *mlx, int n)
{

}

int 	incase(t_mlx *mlx, const char *line)
{
	int 	i;

	i = 0;
	while (line[i] && (line[i] >= '0' && line[i] <= '9' || line[i] == ' '))
		i++;
	if (line[i])
		return (0);
	i = 0;
	while (line[i] && (line[i] >= '0' && line[i] <= '9' || line[i] == ' '))
	{
		if (line[i] >= '0' && line[i] <= '9')
			incase_xyz(mlx, ft_atoi(&line[i]));
		i++;
	}
	return (1);
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
		free(mlx);
		return (NULL);
	}
	close(mlx->fd);
//	mlx->fd = open(av[1], O_RDONLY);
//	while (get_next_line(mlx->fd, &line) > 0)
//	{
//		incase("%s\n", line);
//		free(line);
//	}
	return (mlx);
}