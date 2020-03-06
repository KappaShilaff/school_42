#include <stdio.h>
#include <unistd.h>
#include "stdlib.h"
int		ft_printf(const char *format, ...);

int		main(void)
{
    char    *str;

    str = "% 10s";
    printf("MOE\n");
    ft_printf(str, "lol");
    printf("\nORIG\n");
    printf(str, "lol");
    return (0);
}
