#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    int     ded = 1;
    i = ft_printf("{%5p}", 0);
    printf("\n");
    k = printf("%5%");
    printf("\n%d\n%d", i, k);
    return (0);
}