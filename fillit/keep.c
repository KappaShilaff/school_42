/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:51:48 by kdagmer           #+#    #+#             */
/*   Updated: 2019/12/10 12:00:19 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	get_points(char *buff)
{
	t_point	point;
	int		i;

	point.y0 = 3;
	point.y1 = 0;
	point.x0 = 3;
	point.x1 = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == TBLOCK)
		{
			if (i / 5 < point.y0)
				point.y0 = i / 5;
			if (i / 5 > point.y1)
				point.y1 = i / 5;
			if (i % 5 < point.x0)
				point.x0 = i % 5;
			if (i % 5 > point.x1)
				point.x1 = i % 5;
		}
		i++;
	}
	return (point);
}

static t_piece	*get_piece(char *buff)
{
	t_piece		*newp;
	t_point		ps;
	int			y;
	int			x;
	static char	c = 'a';

	if (!(newp = (t_piece *)ft_memalloc(sizeof(t_piece))))
		print_error(1);
	newp->x = 0;
	newp->y = 0;
	newp->letter = c++;
	newp->next = NULL;
	ps = get_points(buff);
	newp->width = ps.x1 - ps.x0 + 1;
	newp->height = ps.y1 - ps.y0 + 1;
	if (!(newp->map = (char **)malloc((newp->height + 1) * sizeof(char *))))
		print_error(1);
	y = 0;
	while (y < newp->height)
	{
		x = 0;
		newp->map[y] = ft_strnew(newp->width);
		while (x < newp->width)
		{
			if (buff[(ps.y0 + y) * 5 + ps.x0 + x] == TBLOCK)
				newp->map[y][x] = newp->letter;
			else
				newp->map[y][x] = buff[(ps.y0 + y) * 5 + ps.x0 + x];
			x++;
		}
		y++;
	}
	newp->map[y] = NULL;
	return (newp);
}

void			keep(t_tetris *tetris, char *buff)
{
	t_piece *next;
	t_piece *temp;

	next = get_piece(buff);
	temp = tetris->pieces;
	if (temp == NULL)
	{
		tetris->pieces = next;
		tetris->nb_pieces++;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = next;
	tetris->nb_pieces++;
	if (tetris->nb_pieces > 26)
		print_error(1);
}
