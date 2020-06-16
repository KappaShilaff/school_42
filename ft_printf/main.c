#include "ft_printf.h"
#include "srcs/libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int				main(void)
{
//    char *res;
//    res = ft_chexp("0.5", 100000);
//    int     i, k;
//    int     ded = 1;
//        ft_printf("%s\n", "lol");
//    i = ft_printf("%#.3o", 1);
//    printf("\n");
//    ft_printf("%f", (double)-123.1);
//    printf("\n%-100.100f", (double)123.1);
//    printf("hehe %d\n", (((unsigned long int)(double)-100 >> 62) & 1u));
//    printf("%.5f\n", 0.3+0.3+0.3);
//    printf("%s\n", res);
//    free(res);
//      printf("%s\n", bin2str("0.111111111111111111111111111111111\0"));
//      printf("%s\n", ft_chexp("0.5", 2));
//      printf("%s\n", ft_chsum("100.0", "15.250"));
//    res = bin2str("0.111111");
    ft_printf("{%f}{%f}{%Lf}\n", -1444565444646.6465424242242454654,  -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
    printf("{%f}{%f}{%Lf}", -1444565444646.6465424242242454654,  -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
//    ft_printf("%f\n", (double)-2.123123123);
//    printf("%+ 050.32Lf\n", (long double)5.123);
//printf("%d", sizeof(double));
//    ft_printf("% +050d\n", 50123);
//    printf("% +050d\n", 50123);
//    free(res);
    return (0);
}