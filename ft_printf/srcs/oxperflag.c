/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxperflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:27:50 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/29 19:30:11 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_ox_part_minus(struct s_part *part, char type)
{
	if (part->hashtag == 1)
	{
		if (type == 'x')
			write(ft_int_out(part, 2), "0x", 2);
		if (type == 'X')
			write(ft_int_out(part, 2), "0X", 2);
		if (type == 'o')
			write(ft_int_out(part, 1), "0", 1);
	}
	if (part->size > part->len)
		ft_filler(part, part->size - part->len, '0');
	if (part->len != 0)
	{
		ft_putstr(part->number);
		if (part->len != 0 && part->nb_z != 0)
			free(part->number);
		ft_int_out(part, part->len);
	}
	if (part->field >= part->size)
		ft_filler(part, part->field - part->size, ' ');
	return (1);
}

int		ft_ox_part_nominus(struct s_part *part, char type)
{
	if (part->zero == 0 || part->points == 1)
		ft_filler(part, part->field - part->size, ' ');
	if (part->hashtag == 1)
	{
		if (type == 'x')
			write(ft_int_out(part, 2), "0x", 2);
		if (type == 'X')
			write(ft_int_out(part, 2), "0X", 2);
		if (type == 'o')
			write(ft_int_out(part, 1), "0", 1);
	}
	if (part->zero == 1 && part->points == 0)
		ft_filler(part, part->field - part->size, '0');
	ft_filler(part, part->size - part->len, '0');
	if (part->len != 0)
	{
		ft_putstr(part->number);
		if (part->len != 0 && part->nb_z != 0)
			free((part->number));
		ft_int_out(part, part->len);
	}
	return (1);
}

void	ft_oxnumber(struct s_part *part, char type)
{
	if (part->ll == 1 || part->l == 1)
		part->nb_z = va_arg(*part->arg, unsigned long int);
	else if (part->h == 1)
		part->nb_z = (unsigned short int)va_arg(*part->arg, int);
	else if (part->hh == 1)
		part->nb_z = (unsigned char)va_arg(*part->arg, int);
	else
		part->nb_z = (unsigned long int)va_arg(*part->arg, unsigned int);
	if (type == 'x' || type == 'X')
		part->number = ft_unsigned_itoa_base(part->nb_z, 16, type);
	else
		part->number = ft_unsigned_itoa_base(part->nb_z, 8, 'X');
	if (part->nb_z == 0)
	{
		if (part->hashtag == 1)
			part->nb_ll = 1;
		part->hashtag = 0;
	}
	if (part->hashtag == 1)
	{
		part->field -= 2;
		if (type == 'o')
			norm_for_ft_oxnumber(part);
	}
}

int		ft_oxflag(char *str, struct s_part *part, char type)
{
	ft_parsing(part, &str, type);
	ft_oxnumber(part, type);
	part->len = ft_strlen(part->number);
	if (!(part->nb_ll == 1 && type == 'o' &&
	part->nb_z == 0 && part->size == 0))
		if (part->size == 0 && part->points == 1 && part->nb_z == 0)
			part->len = 0;
	if (part->len > part->size)
		part->size = part->len;
	if (part->size > part->field)
		part->field = part->size;
	if (part->minus == 1)
		return (ft_ox_part_minus(part, type));
	return (ft_ox_part_nominus(part, type));
}

int		ft_perflag(char *str, struct s_part *part)
{
	ft_parsing(part, &str, '%');
	if (part->size > part->field)
		part->field = part->size;
	if (part->minus == 1)
		write(ft_int_out(part, 1), "%", 1);
	if (part->zero == 1)
		ft_filler(part, part->field - 1, '0');
	else
		ft_filler(part, part->field - 1, ' ');
	if (part->minus == 0)
		write(ft_int_out(part, 1), "%", 1);
	return (1);
}
