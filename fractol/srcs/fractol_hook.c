/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mouse_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:25:47 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/05 16:36:27 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		fr_mouse(int code, int x, int y, t_fr *fr)
{
	if (code == 4 || code == 1)
	{
		fr_zoom(fr, x, y);
		fr_draw(fr);
	}
	else if (code == 5 || code == 2)
	{
		fr_dezoom(fr, x, y);
		fr_draw(fr);
	}
	return (0);
}

int		fr_key(int code, t_fr *fr)
{
	if (code == 53)
	{
		free(fr);
		exit(0);
	}
	return (0);
}
