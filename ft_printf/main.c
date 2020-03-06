#include <stdio.h>
#include <unistd.h>
#include "stdlib.h"
int		ft_printf(const char *format, ...);

int		main(void)
{
    char    *str;

    str = "%10d";
    printf("MOE\n");
    ft_printf(str, 50);
    printf("\nORIG\n");
    printf(str, 50);
    return (0);
}
