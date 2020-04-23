#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    i = ft_printf("%1c", NULL);
    printf("\n");
    k = printf("%1c", NULL);
    printf("\n%d\n%d", i, k);
    return (0);
}