#include <stdio.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);

int		main(void)
{
    char    *str;
    str = "% 10s%s";
    ft_printf(str, "lol", " kek\n");
    printf(str, "lol", " kek");
    return (0);
}
