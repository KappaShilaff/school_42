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
    ft_printf("%f", (double)5.1);
    printf("\n%.49f", (double)5.1);
//    printf("hehe %d\n", (((unsigned long int)(double)-100 >> 62) & 1u));
//    printf("%.5f\n", 0.3+0.3+0.3);
//    printf("%s\n", ft_chmult("100.0", "1.0"));
//      printf("%s\n", bin2str("0.111111111111111111111111111111111\0"));
//      printf("%s\n", ft_chexp("0.5", 2));
//    printf("%s\n", ft_chsum("0.0", "0.25"));
    return (0);
}