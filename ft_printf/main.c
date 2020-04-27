#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    int     ded = 1;
    i = ft_printf("%#.3o", 1);
    printf("\n");
    k = printf("%#.3o", 1);
    printf("\n%d\n%d", i, k);
    return (0);
}