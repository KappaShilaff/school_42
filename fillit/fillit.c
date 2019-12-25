/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:30:35 by kdagmer           #+#    #+#             */
/*   Updated: 2019/12/25 13:55:35 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		addtomap(t_tetris *tetris, t_piece *tet, int y, int x)
{
	while (y < tet->height)
	{
		x = 0;
		while (x < tet->width)
		{
			if (tetris->map[y + tet->y][x + tet->x] != TEMPTY &&\
					tet->map[y][x] != TEMPTY)
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
			x++;
		}
		y++;
	}
	return (1);
}

void			removetomap(t_tetris *tetris, t_piece *tet)
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

static int		placer(t_tetris *tetris, t_piece *tet)
{
	if (!tet)
		return (1);
	tet->y = 0;
	tet->x = 0;
	while (tet->y + tet->height <= tetris->size)
	{
		tet->x = 0;
		while (tet->x + tet->width <= tetris->size)
		{
			if (addtomap(tetris, tet, 0, 0))
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
}

int				solver(t_tetris *tetris)
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
	}
	if (k == 1)
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	t_tetris	tetris;
	t_piece		*temp;
	int			i;

	if (ac != 2)
	{
		print_error(2);
		return (0);
	}
	if (tet_create(&tetris, av[1]))
	{
		while (solver(&tetris) == 0)
			i = i + 1 - 1;
		print_map(&tetris);
		temp = tetris.pieces;
		while (temp && (i *= 0) == 0)
		{
			while (temp->map[i] != NULL)
				i++;
			temp = temp->next;
		}
	}
	else
		print_error(1);
	return (1);
}
