/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:44:28 by kdagmer           #+#    #+#             */
/*   Updated: 2019/12/10 13:03:34 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** map create
*/

static int		map(t_tetris *tetris, int size)
{
	int i;

	if (!(tetris->map = (char **)malloc(size * sizeof(char *))))
		return (0);
	i = 0;
	printf("\n\n\n--------empty map--------\n\n\n");
	while (i < size)
	{
		if (!(tetris->map[i] = (char *)malloc(size * sizeof(char))))
			return (0);
		ft_memset(tetris->map[i], TEMPTY, size);
		printf("%s\n", tetris->map[i]);
		i++;
	}
	printf("\n\n\n");
	printf("----------\nnb_pieces: %d\nsizeofmap: %d\n--------\n", tetris->nb_pieces, size);
	return (1);
}

int				tet_create(t_tetris *tetris, char *file)
{
	int sd; //side size

	sd = 1;
	tetris->pieces = NULL;
	tetris->map = NULL;
	tetris->nb_pieces = 0;
	if (check_file(tetris, file))
	{
		map(tetris, 4 * tetris->nb_pieces);
		while (sd * sd < tetris->nb_pieces)
			sd++;
		tetris->size = sd * 2; // -1
		printf("tetsize: %d\n", tetris->size);
		return (1);
	}
	return (0);
}
