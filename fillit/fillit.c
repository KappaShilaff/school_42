/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:30:35 by kdagmer           #+#    #+#             */
/*   Updated: 2019/12/10 10:49:29 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		place(t_tetris *tetris, t_piece *tet)
{
	int y;
	int x;

	y = 0;
	if (tetris->map[tet->y][tet->x] == TEMPTY)
	{
		while (y < tet->height)
		{
			x = 0;
			while (x < tet->width)
			{
				tetris->map[y][x] = tet->map[y][x];
				x++;
			}
			y++;
		}
	}
	return (0);
}

void			solve(t_tetris *tetris)
{
	while (tetris->pieces->y + tetris->pieces->height > tetris->size || \
			tetris->pieces->x + tetris->pieces->width > tetris->size)
	{
		printf("h%d\n", tetris->pieces->height);
		printf("w%d\n", tetris->pieces->width);
		printf("s%d\n", tetris->size);
		tetris->size++;
	}
	printf("h%d\n", tetris->pieces->height);
	printf("w%d\n", tetris->pieces->width);
	printf("s%d\n", tetris->size);
	place(tetris, tetris->pieces);
}

void			print_map(t_tetris *tetris)
{
	int y;
	int x;

	y = 0;
	while (y < tetris->size)
	{
		x = 0;
		while (x < tetris->size)
			ft_putchar(tetris->map[y][x++]);
		ft_putchar('\n');
		y++;
	}
}

int				main(int ac, char **av)
{
	t_tetris tetris;
	t_piece *temp;
	int i;

	if (ac != 2)
	{
		print_error(2);
		return (0);
	}
	if (tet_create(&tetris, av[1]))
	{
		solve(&tetris);
		printf("\n\n\n--------print map--------\n\n\n");
		print_map(&tetris);
		printf("\n\n\n");
		/*printf("%s\n", tetris.pieces->map[0]);
		printf("%s\n", tetris.pieces->next->map[0]);
		printf("%s\n", tetris.pieces->next->map[1]);
		printf("%s\n", tetris.pieces->next->map[2]);
		printf("%s\n", tetris.pieces->next->next->map[0]);
		printf("%s\n", tetris.pieces->next->next->map[1]);
		printf("%s\n", tetris.pieces->next->next->next->map[0]);
		printf("%s\n", tetris.pieces->next->next->next->map[1]);
		printf("%s\n", tetris.pieces->next->next->next->next->map[0]);
		printf("%s\n", tetris.pieces->next->next->next->next->map[1]);
		printf("---------\n");*/
		temp = tetris.pieces;
		while (temp)
		{
			i = 0;
			while (temp->map[i] != NULL)
			{
				printf("%d %s\n", i, temp->map[i]);
				i++;
			}
			temp = temp->next;
		}
	}
	else
		print_error(1);
	return (1);
}
