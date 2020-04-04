#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    i = ft_printf("%zd", -1);
    printf("\n");
    k = printf("%zd", -1);
    printf("\n%d\n%d", i, k);
    return (0);
}