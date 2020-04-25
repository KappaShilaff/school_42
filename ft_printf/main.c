#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    int     ded = 1;
    i = ft_printf("%c", 0);
    printf("\n");
    k = printf("%c", 0);
    printf("\n%d\n%d", i, k);
    return (0);
}