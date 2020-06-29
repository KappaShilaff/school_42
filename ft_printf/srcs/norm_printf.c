/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:42:41 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/29 20:02:49 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int		ft_help_for_ft_flag(struct s_part *part, char *str)
{
	if (str[part->n] == 'x' && !ft_oxflag((part->format), part, 'x'))
		return (1);
	if (str[part->n] == 'X' && !ft_oxflag((part->format), part, 'X'))
		return (1);
	if (str[part->n] == 'o' && !ft_oxflag((part->format), part, 'o'))
		return (1);
	if (str[part->n] == 'i' && !ft_dflag((part->format), part, 'i'))
		return (1);
	if (str[part->n] == 'u' && !ft_uflag((part->format), part))
		return (1);
	if (str[part->n] == 'p' && !ft_pflag((part->format), part, 'x'))
		return (1);
	if (str[part->n] == 'f' && !ft_fflag((part->format), part))
		return (1);
}

int		ft_int_out(struct s_part *this, int i)
{
	this->int_out += i;
	return (1);
}

int		ft_filler(struct s_part *this, long int i, char k)
{
	char		*out;
	long int	temp;

	if (i <= 0)
		return (0);
	temp = i;
	out = malloc(i + 1);
	while (i-- > 0)
		out[i] = k;
	write(ft_int_out(this, (int)temp), out, temp);
	free(out);
	return (0);
}

void	help_for_ft_helpforparsing(struct s_part *part, char **str)
{
	if (**str == '-')
		part->minus = 1;
	if (**str == '+')
		part->plus = 1;
	if (**str == 'L')
		part->L = 1;
	if (**str == '0')
		part->zero = 1;
}

void	help_for_ft_fill_struct(struct s_part *this)
{
	this->field = 0;
	this->L = 0;
	this->hh = 0;
	this->h = 0;
	this->j = 0;
	this->z = 0;
	this->space = 0;
	this->negative = 0;
	this->points = 0;
	this->flags = 0;
	this->nb_ll = 0;
	this->nb_z = 0;
	this->size = 0;
	this->e = -1023;
	this->f = 0;
}
