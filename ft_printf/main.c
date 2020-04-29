#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int				main(void)
{
//    int     i, k;
//    int     ded = 1;
//    i = ft_printf("%#.3o", 1);
//    printf("\n");
    ft_printf("%f", (double)6);
    printf("%d", (unsigned long int)(double)-1 >> 63 & 1u);
//    printf("\n%d\n%d", i, k);
    return (0);
}