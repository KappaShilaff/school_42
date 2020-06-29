/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idflag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:25:03 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/29 19:27:18 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void	norme_for_ft_dnumber(struct s_part *part)
{
	part->negative = 1;
	part->plus = 0;
	part->space = 0;
	part->len = -1;
}

void	ft_dnumber(struct s_part *part)
{
	if (part->ll == 1)
		part->nb_ll = va_arg(*part->arg, long long int);
	else if (part->l == 1)
		part->nb_ll = va_arg(*part->arg, long int);
	else if (part->h == 1)
		part->nb_ll = (long long int)(short int)(va_arg(*part->arg, int));
	else if (part->hh == 1)
		part->nb_ll = (long long int)(char)(va_arg(*part->arg, int));
	else
		part->nb_ll = (long long int)(va_arg(*part->arg, int));
	if (part->nb_ll < 0)
		norme_for_ft_dnumber(part);
	if (part->points == 1)
		part->zero = 0;
	if (part->plus == 1)
		part->space = 0;
	part->len += ft_strlen_ll_nb(part->nb_ll);
	part->num = ft_itoa(part->nb_ll);
	if (part->negative == 1)
		(part->num)++;
	if (part->points == 1 && part->nb_ll == 0)
		part->len -= 1;
}

int		ft_part_minus(struct s_part *part)
{
	if (part->negative == 1)
		write(ft_int_out(part, 1), "-", 1);
	if (part->plus == 1)
		write(ft_int_out(part, 1), "+", 1);
	if (part->space == 1)
		write(ft_int_out(part, 1), " ", 1);
	if (part->size > part->len)
		ft_filler(part, part->size - part->len, '0');
	write(ft_int_out(part, part->len), part->num, part->len);
	if (part->negative == 1)
		part->num--;
	free(part->num);
	if (part->field >= part->size)
		ft_filler(part, part->field - part->size, ' ');
	return (1);
}

int		ft_part_nominus(struct s_part *part)
{
	if (part->negative == 1 && part->zero == 1)
		write(ft_int_out(part, 1), "-", 1);
	if (part->plus == 1 && part->zero == 1)
		write(ft_int_out(part, 1), "+", 1);
	if (part->space == 1)
		write(ft_int_out(part, 1), " ", 1);
	if (part->zero == 1)
		ft_filler(part, part->field - part->size, '0');
	else
		ft_filler(part, part->field - part->size, ' ');
	if (part->negative == 1 && part->zero == 0)
		write(ft_int_out(part, 1), "-", 1);
	if (part->plus == 1 && part->zero == 0)
		write(ft_int_out(part, 1), "+", 1);
	if (part->size > part->len)
		ft_filler(part, part->size - part->len, '0');
	write(ft_int_out(part, part->len), part->num, part->len);
	if (part->negative == 1 && part->f == 0)
		part->num--;
	free(part->num);
	return (1);
}

int		ft_dflag(char *str, struct s_part *part, char type)
{
	ft_parsing(part, &str, type);
	ft_dnumber(part);
	if (part->negative == 1 || part->plus == 1 || part->space == 1)
		part->field -= 1;
	if (part->len > part->size)
		part->size = part->len;
	if (part->size > part->field)
		part->field = part->size;
	if (part->minus == 1)
		return (ft_part_minus(part));
	return (ft_part_nominus(part));
}
