#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"


void    ft_fnumber(struct s_part *part)
{
    unsigned long int    e, k, l, kek, mt;
    unsigned long int     i[52];

    char    *mant;

    mant = malloc(55);
    mant[54] = '\0';
    mt = 53;
    e = -1023;
    k = 1;
    i[0] = 1;
    while (k < 52) {
        i[k] = i[k - 1] * 2;
        k++;
    }
    part->dnum = va_arg(*part->arg, double);
    ft_memcpy(&kek, &part->dnum, 8);
    k = 0;
    l = 0;
    while (k < 52)
    {
        if (((kek >> l) & 1u) == 1) {
            write(1, "1", 1);
            mant[mt] = '1';
        } else {
            write(1, "0", 1);
            mant[mt] = '0';
        }
        mt--;
        l++;
        k++;
    }
    mant[1] = '.';
    mant[0] = '1';
    k = 0;
    while (k < 11)
    {
        if (((kek >> l) & 1u) == 1) {
            e += i[k];
            write(1, "1", 1);
        } else {
            write(1, "0", 1);
        }
        l++;
        k++;
    }
    if (((kek >> l & 1u)) == 1) {
        part->negative = 1;
        write(1, "1", 1);
    }
    else {
        write(1, "0", 1);
    }
    printf("\nmantissa %s", mant);
    printf("\ne %llu\n", e);
}

int     ft_fflag(char *str, struct s_part *part)
{
    ft_parsing(part, &str, 'f');
    ft_fnumber(part);
    return (1);
}

