/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:35:46 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/29 19:36:18 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void	ft_unumber(struct s_part *part)
{
	if (part->ll == 1)
		part->nb_z = va_arg(*part->arg, unsigned long long);
	else if (part->l == 1)
		part->nb_z = (unsigned long long)va_arg(*part->arg, unsigned long long);
	else if (part->h == 1)
		part->nb_z = (unsigned short int)(va_arg(*part->arg, unsigned int));
	else if (part->hh == 1)
		part->nb_z = (unsigned char)(va_arg(*part->arg, unsigned int));
	else
		part->nb_z = (va_arg(*part->arg, unsigned int));
	if (part->points == 1)
		part->zero = 0;
	part->len = ft_strlen_z_nb(part->nb_z);
	part->num = ft_unsigned_itoa_base(part->nb_z, 10, 'x');
	if (part->points == 1 && part->nb_z == 0)
		part->len -= 1;
}

int		ft_upart_minus(struct s_part *part)
{
	if (part->size > part->len)
		ft_filler(part, part->size - part->len, '0');
	write(ft_int_out(part, part->len), part->num, part->len);
	if (part->len != 0 && part->nb_z != 0)
		free(part->num);
	if (part->field >= part->size)
		ft_filler(part, part->field - part->size, ' ');
	return (1);
}

int		ft_upart_nominus(struct s_part *part)
{
	if (part->zero == 1)
		ft_filler(part, part->field - part->size, '0');
	else
		ft_filler(part, part->field - part->size, ' ');
	if (part->size > part->len)
		ft_filler(part, part->size - part->len, '0');
	write(ft_int_out(part, part->len), part->num, part->len);
	if (part->len != 0 && part->nb_z != 0)
		free(part->num);
	return (1);
}

int		ft_uflag(char *str, struct s_part *part)
{
	ft_parsing(part, &str, 'u');
	ft_unumber(part);
	if (part->negative == 1 || part->plus == 1 || part->space == 1)
		part->field -= 1;
	if (part->len > part->size)
		part->size = part->len;
	if (part->size > part->field)
		part->field = part->size;
	if (part->minus == 1)
		return (ft_upart_minus(part));
	return (ft_upart_nominus(part));
}
