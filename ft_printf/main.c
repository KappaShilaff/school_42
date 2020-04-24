#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    i = ft_printf("%lu", -42);
    printf("\n");
    k = printf("%lu", -42);
    printf("\n%d\n%d", i, k);
    return (0);
}