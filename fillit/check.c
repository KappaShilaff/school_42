/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:28:21 by kdagmer           #+#    #+#             */
/*   Updated: 2019/12/10 10:47:28 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_valid(int c, int i)
{
	if (c == TBLOCK || c == TEMPTY || \
		((c == '\n') && ((i % 5 == 4) || (i == 20))))
		return (1);
	return (0);
}

static int		check_neighbour(char *buff, int i)
{
	int nb;

	nb = 0;
	if (i == 19)
		return (0);
	if (buff[i] == TBLOCK)
	{
		if (i < 19 && (buff[i + 1] == TBLOCK))
			nb++;
		if (i > 0 && (buff[i - 1] == TBLOCK))
			nb++;
		if (i <= 14 && (buff[i + 5] == TBLOCK))
			nb++;
		if (i >= 5 && (buff[i - 5] == TBLOCK))
			nb++;
	}
	return (nb + check_neighbour(buff, ++i));
}

static int		check_block(char *buff, int dot)
{
	int i;
	int sum;
	int first;
	int nb;

	i = 0;
	sum = 0;
	while (buff[i] && sum <= 4 && dot <= 12 && is_valid(buff[i], i))
	{
		if (buff[i] == TBLOCK)
		{
			sum++;
			if (sum == 1)
				first = i;
		}
		if (buff[i] == TEMPTY)
			dot++;
		i++;
	}
	printf("%d\n", i); // remove
	printf("%d\n", sum); // remove
	if (i >= 20 && !buff[i] && sum == 4 && \
		(nb = check_neighbour(buff, first)) && (nb == 6 || nb == 8))
	{
		printf("nbl: %d\n", nb); // remove
		return (1);
	}
	else
		print_error(3); // change to 1
	return (0);
}

int				check_file(t_tetris *tetris, char *file)
{
	int		fd;
	int		r;
	int		lastr;
	char	buff[22];

	r = 0;
	lastr = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error(1);
	while ((r = read(fd, buff, 21)) > 0)
	{
		lastr = r;
		buff[r] = '\0';
		if (r >= 20 && check_block(buff, 0))
		{
			keep(tetris, buff);
			printf("%s", buff);
		}
		else
			print_error(1);
	}
	if (r <= 0 && (lastr == 21 || !lastr))
		print_error(1);
	return (1);
}
