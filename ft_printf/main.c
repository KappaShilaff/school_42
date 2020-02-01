#include <stdio.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);

int		main(void)
{
    ft_printf("%2s", "lol");
    return (0);
}
