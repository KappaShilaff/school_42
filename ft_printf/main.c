#include <stdio.h>
#include <unistd.h>
#include "stdlib.h"
int		ft_printf(const char *format, ...);

int		main(void)
{

//    char    *str;
//    str = "%321-   0 0 0     0    0       -  123123  *s%s";
//    printf("MOE\n");
//    ft_printf(str, "lol", " kek");


//    printf("\nORIG\n");
//    printf(str, "lol", " kek");
    ft_printf("%+-010zd\n", 50, 50, 50);
    printf("%+-010zd",  50);

    return (0);
}
