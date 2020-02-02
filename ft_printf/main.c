#include <stdio.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);

int		main(void)
{
    char    *str;
    str = "%321-   0 0 0     0    0       -  123123  *s%s";
    printf("MOE\n");
    ft_printf(str,"lol", " kek");
    printf("\nORIG\n");
    printf(str, "lol", " kek");
    return (0);
}
