/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:30:35 by kdagmer           #+#    #+#             */
/*   Updated: 2019/12/25 13:25:51 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_map(t_tetris *tetris);

/*static int		removelast(t_tetris *tetris, t_piece *tet)
{
	return (0);
}*/

static int		addtomap(t_tetris *tetris, t_piece *tet)
{
	int y;
	int x;

	y = 0;
	//tetris->size = 5;
	//printf("h: %d\n", tet->height);
	//printf("w: %d\n", tet->width);
	while (y < tet->height)
	{
		x = 0;
		while (x < tet->width)
		{
			if (tetris->map[y + tet->y][x + tet->x] != TEMPTY && tet->map[y][x] != TEMPTY)
				return (0);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < tet->height)
	{
		x = 0;
		while (x < tet->width)
		{
			if (tet->map[y][x] != TEMPTY)
				tetris->map[y + tet->y][x + tet->x] = tet->map[y][x];
//			print_map(tetris);
			x++;
		}
		y++;
	}
//	printf("LOL 1\n");
	return (1);
}

void	removetomap(t_tetris *tetris, t_piece *tet)
{
	int		x;
	int		y;

	y = 0;
	while (y < tet->height)
	{
		x = 0;
		while (x < tet->width)
		{
			if (tet->map[y][x] != TEMPTY)
				tetris->map[y + tet->y][x + tet->x] = TEMPTY;
			x++;
		}
		y++;
	}
}


/*
									  solver (if placer 0 : size++)
										|
										placer (if addtomap 1 : placer)
										/
								addtomap
								/		\
			if 1 : placer next tet		if 0 : removelast
*/

static int		placer(t_tetris *tetris, t_piece *tet)
{
	if (!tet)
		return (1);
	tet->y = 0;
	tet->x = 0;
//	printf("htet: %d\n", tet->height);
//	printf("wtet: %d\n", tet->width);
	while (tet->y + tet->height <= tetris->size)
	{
		tet->x = 0;
		while (tet->x + tet->width <= tetris->size)
		{
			if (addtomap(tetris, tet))
			{
				if (placer(tetris, tet->next) == 1)
					return (1);
				else
					removetomap(tetris, tet);
			}
			tet->x++;
		}
		tet->y++;
	}
	if (tet->letter == 'A')
		return (3);
	return (0);
//	removelast
}

int			solver(t_tetris *tetris)
{
	int		y;
	int		x;
	int		k;
	y = 0;
	while ((k = (placer(tetris, tetris->pieces))) == 3)
	{
		while (y < tetris->size)
		{
			x = 0;
			while (x < tetris->size)
			{
				tetris->map[y][x] = TEMPTY;
				x++;
			}
			y++;
		}
		tetris->size++;
//		printf("tetsize: %dx%d\n", tetris->size, tetris->size);
//		print_map(tetris);
//		ft_memset();
	}
	if (k == 1)
		return (1);
	return (0);
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
	int	mem;
	mem = 0;

	if (ac != 2)
	{
		print_error(2);
		return (0);
	}
	if (tet_create(&tetris, av[1]))
	{
		while (solver(&tetris) == 0)
			mem++;
//		printf("\n\n\n--------print map--------\n\n\n");
		print_map(&tetris);
//		printf("\n\n\n");
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
//				printf("%d %s\n", i, temp->map[i]);
				i++;
			}
			temp = temp->next;
		}
	}
	else
		print_error(1);
	return (1);
}
