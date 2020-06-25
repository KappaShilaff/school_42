#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static size_t	digit_count(size_t nb, int base)
{
    size_t		i;

    i = 0;
    while (nb)
    {
        nb /= base;
        i++;
    }
    return (i);
}

char			*ft_unsigned_itoa_base(size_t value, int base, char x)
{
    char	*ret;
    char	*tab_base;
    size_t		taille;
    size_t		i;
    size_t		sign;

    if (base < 2 || base > 16)
        return (0);
    sign = 0;
    if (value == 0)
        return ("0");
//    tab_base = (char *)malloc(sizeof(char) * 17);
    if (x == 'X')
        tab_base = "0123456789ABCDEF";
    else
        tab_base = "0123456789abcdef";
    taille = digit_count(value, base);
    taille += (sign ? 1 : 0);
    ret = (char *)malloc(sizeof(char) * (taille + 1));
    i = 1;
    sign ? (ret[0] = '-') : 0;
    while (value != 0)
    {
        ret[taille - i++] = tab_base[value % base];
        value /= base;
    }
    ret[taille] = '\0';
//    free(tab_base);
    return (ret);
}

