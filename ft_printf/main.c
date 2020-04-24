#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    int     ded = 1;
    i = ft_printf("%p", 0);
    printf("\n");
    k = printf("%p", 0);
    printf("\n%d\n%d", i, k);
    return (0);
}