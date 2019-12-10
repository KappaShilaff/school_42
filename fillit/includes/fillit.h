/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:03:11 by kdagmer           #+#    #+#             */
/*   Updated: 2019/12/10 10:45:49 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h> // remove

# define TBLOCK '#'
# define TEMPTY '.'

# define ERR1 "error\n"
# define ERR2 "usage: ./fillit source_file\n"
# define ERR3 "flag err\n" // remove

typedef struct		s_point
{
	int y0;
	int y1;
	int x0;
	int x1;
}					t_point;

typedef struct		s_piece
{
	int				x;
	int				y;
	int				width;
	int				height;
	char			letter;
	char			**map;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_tetris
{
	t_piece			*pieces;
	int				nb_pieces;
	int				size;
	char			**map;
}					t_tetris;

void				print_error(int n);
int					check_file(t_tetris *tetris, char *file);
void				keep(t_tetris *tetris, char *buff);
int					tet_create(t_tetris *tetris, char *file);

#endif
