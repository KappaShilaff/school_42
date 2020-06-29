/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scflag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:32:39 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/29 19:35:19 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_sflag(char *str, struct s_part *part)
{
	char	*out;

	ft_parsing(part, &str, 's');
	out = va_arg(*part->arg, char *);
	if (out == NULL)
	{
		out = "(null)";
		if (part->size < 6)
			part->size = 6;
	}
	part->len = ft_strlen(out);
	if (part->points == 1 && part->size < part->len)
		part->len = part->size;
	if (part->minus == 1)
	{
		write(ft_int_out(part, part->len), out, part->len);
		ft_filler(part, part->field - part->len, ' ');
	}
	else
	{
		ft_filler(part, part->field - part->len, ' ');
		write(ft_int_out(part, part->len), out, part->len);
	}
	return (1);
}

int		ft_cflag(char *str, struct s_part *part)
{
	char	out;

	ft_parsing(part, &str, 'c');
	out = va_arg(*part->arg, int);
	if (part->minus == 1)
	{
		write(ft_int_out(part, 1), &out, 1);
		ft_filler(part, (long int)(part->field - 1), ' ');
	}
	else
	{
		ft_filler(part, (long int)(part->field - 1), ' ');
		write(ft_int_out(part, 1), &out, 1);
	}
	return (1);
}
