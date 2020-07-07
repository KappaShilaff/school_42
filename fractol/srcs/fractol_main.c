/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:24:09 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/07 16:02:36 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int 	fr_error(char *str, int i_switch)
{
	ft_putstr_fd(str, 2);
	if (i_switch == 1)
		ft_putstr_fd("Valid number of arguments : 1\n", 2);
	if (i_switch == 2)
		ft_putstr_fd("Valid argument : Julia, Mandelbrot, Chameleon, Burningship\n", 2);
	return (0);
}

static int 	fr_valid_argv(t_fr **fr)
{
	if (ft_strcmp(fr[0]->argv, "Julia") == 0)
		fr_julia(fr);
	else if (ft_strcmp(fr[0]->argv, "Mandelbrot") == 0)
		fr_mandelbrot(fr);
	else if (ft_strcmp(fr[0]->argv, "Chameleon") == 0)
		fr_chameleon(fr);
	else if (ft_strcmp(fr[0]->argv, "Burningship") == 0)
		fr_ship(fr);
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fr					**fr;
	pthread_t 				*thread_id;

	thread_id = (pthread_t *)malloc(4 * sizeof(pthread_t));
	if (argc != 2)
	{
		return (fr_error("Invalid number of arguments\n", 1));
	}
	fr = (t_fr **)malloc(sizeof(t_fr *) * 4);
	fr[0] = (t_fr *)malloc(sizeof(t_fr));
	fr[1] = (t_fr *)malloc(sizeof(t_fr));
	fr[2] = (t_fr *)malloc(sizeof(t_fr));
	fr[3] = (t_fr *)malloc(sizeof(t_fr));
	fr[0]->argv = argv[1];
	fr[0]->menu = 340;
	fr[0]->thread_id = thread_id;
	if (fr_valid_argv(fr) == 0)
		return (fr_error("Invalid argument\n", 2));
	return (0);
}
