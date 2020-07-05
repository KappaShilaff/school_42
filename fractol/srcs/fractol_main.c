/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:24:09 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/05 15:43:11 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int 	fr_error(char *str, int i_switch)
{
	ft_putstr_fd(str, 2);
	if (i_switch == 1)
		ft_putstr_fd("Valid number of arguments : 1\n", 2);
	if (i_switch == 2)
		ft_putstr_fd("Valid argument : Julia\n", 2);
	return (0);
}

static int 	fr_valid_argv(t_fr *fr)
{
	if (ft_strcmp(fr->argv, "Julia") == 0)
		fr_julia(fr);
	else if (ft_strcmp(fr->argv, "Mandelbrot") == 0)
		fr_mandelbrot(fr);
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fr	*fr;

	if (argc != 2)
		return (fr_error("Invalid number of arguments\n", 1));
	if (!(fr = malloc(sizeof(t_fr))))
		return (fr_error("Struct malloc error\n", 3));
	fr->argv = argv[1];
	if (fr_valid_argv(fr) == 0)
		return (fr_error("Invalid argument\n", 2));
	return (0);
}
