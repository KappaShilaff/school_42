#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
    int     i, k;
    i = ft_printf("@moulitest: %#.o %#.0o", 0, 0);
    printf("\n");
    k = printf("@moulitest: %.o %.0o", 0, 0);
    printf("\n%d\n%d", i, k);
    return (0);
}