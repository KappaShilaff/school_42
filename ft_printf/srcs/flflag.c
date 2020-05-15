#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static char *mantissa(struct s_part *part, int k, int l)
{
    char    *mant;
    int     mt;
    __uint128_t		*n;
    int     i;

    n = (__uint128_t *)&part->ldnum;
    i = 0;
    while (((*n) >> i & 1) != 1 && i < 63)
        ++i;
    l = 63 - i;
    mant = ft_strnew(l + 2);
    while (l + 1 > 0)
        mant[l-- + 1] = '0' + ((((*n) >> i++) & 1) == 1);
    mant[1] = '.';
    mant[k = 0] = '1';
    part->e = (((*n) << 49 >> 49) >> 64) - 16383;
    if (part->ldnum < 0)
        part->negative = 1;
    return (mant);
}


void flnumber(struct s_part *part)
{
    char    *mant;
    char    *bin;
    char    *exp;
    char    *res;


    mant  = mantissa(part, 1, 0);
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

