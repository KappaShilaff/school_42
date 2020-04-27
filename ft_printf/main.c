#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    int     ded = 1;
    i = ft_printf("{% 05.3d}", 0);
    printf("\n");
    k = printf("{% 05.3d}", 0);
    printf("\n%d\n%d", i, k);
    return (0);
}