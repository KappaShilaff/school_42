/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:31:41 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/29 19:19:43 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static void		norme1(unsigned long int kek, int k[1], int i[15], int l[1])
{
	i[0] = 1;
	while (k[0]++ < 11)
		i[k[0] - 1] = i[k[0] - 2] * 2;
	k[0] = 0;
	while ((k[0] < 52) && (k[0] != 100))
		if (((kek >> l[0]++) & 1u) == 1)
			k[0] = 100;
		else
			k[0]++;
}

static char		*mantissa(struct s_part *part, unsigned long kek, int k, int l)
{
	int		i[11];
	char	*mant;
	int		mt;

	norme1(kek, &k, i, &l);
	mt = 53 - --l;
	mant = ft_chmalloc_zend(mt + 1);
	k = l;
	while (k++ < 52)
		if (((kek >> l++) & 1u) == 1)
			mant[mt--] = '1';
		else
			mant[mt--] = '0';
	mant[1] = '.';
	k = 0;
	mant[k] = '1';
	while (k++ < 11)
		if (((kek >> l++) & 1u) == 1)
			part->e += i[k - 1];
	if (((kek >> l & 1u)) == 1)
		part->negative = 1;
	if ((part->e == -1022 && part->L == 0) || part->e == -16382)
		mant[0] = '0';
	return (mant);
}

void			ft_fnumber(struct s_part *part)
{
	unsigned long int	kek;
	char				*mant;
	char				*bin;
	char				*exp;
	char				*res;

	ft_memcpy(&kek, &part->dnum, 8);
	mant = mantissa(part, kek, 1, 0);
	bin = bin2str(mant);
	free(mant);
	if (part->e > 0)
		exp = ft_chexp("2.0", part->e);
	else
		exp = ft_chexp("0.5", -(part->e));
	res = ft_chmult(exp, bin);
	free(bin);
	free(exp);
	if (part->points == 0)
		mant = ft_chround(res, 6);
	else
		mant = ft_chround(res, part->size);
	free(res);
	part->num = mant;
}

int				ft_fflag(char *str, struct s_part *part)
{
	ft_parsing(part, &str, 'f');
	part->f = 1;
	if (part->L == 1)
	{
		part->ldnum = va_arg(*part->arg, long double);
		flnumber(part);
	}
	else
	{
		part->dnum = va_arg(*part->arg, double);
		ft_fnumber(part);
	}
	part->len = ft_strlen(part->num);
	if (part->plus == 1)
		part->space = 0;
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
