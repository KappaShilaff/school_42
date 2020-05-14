#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"


void    ft_fnumber(struct s_part *part)
{
    int    e, k, l, mt, i[11];
    unsigned long int       kek;
    char    *mant;
    char    *bin;
    char    *exp;
    char    *res;

    e = -1023;
    k = 1;
    i[0] = 1;
    while (k++ < 11)
        i[k - 1] = i[k - 2] * 2;
    part->dnum = va_arg(*part->arg, double);
    ft_memcpy(&kek, &part->dnum, 8);
    k = 0;
    l = 0;
    while (k < 52 && k != 100)
        if (((kek >> l++) & 1u) == 1)
            k = 100;
        else
            k++;
    l -= 1;
    mt = 53 - l;
    mant = ft_chmalloc_zend(mt + 1);
    k = l;
    while (k++ < 52)
        if (((kek >> l++) & 1u) == 1)
            mant[mt--] = '1';
        else
            mant[mt--] = '0';
    mant[1] = '.';
    mant[0] = '1';
    k = 0;
    while (k++ < 11)
        if (((kek >> l++) & 1u) == 1)
            e += i[k - 1];
    if (((kek >> l & 1u)) == 1)
        part->negative = 1;
        if (e == -1022)
            mant[0] = '0';
    bin = bin2str(mant);
    if (e > 0)
        exp = ft_chexp("2.0", e);
    else
        exp = ft_chexp("0.5", -e);
    res = ft_chmult(exp, bin);
    printf("mantissa %s = %s\nexponent %d = %s\nnegative %d\nresult %s", mant, bin, e, exp, part->negative, res);
    free(res);
    free(mant);
    free(bin);
    free(exp);
}

int     ft_fflag(char *str, struct s_part *part)
{
    ft_parsing(part, &str, 'f');
    ft_fnumber(part);
    return (1);
}