#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char    *bin2str(char *str)
{
    char    *res;
    char    *buf;
    int     i;

    i = 2;
    res = ft_strdup("0.0\0");
    while (str[i] != '\0')
    {
        if (str[i] == '1') {
            buf = res;
            res = ft_chsum(res, ft_chexp("0.5", i - 1));
//            free(buf);
        }
        i++;
    }
    if (str[0] == '1')
        res[0] = '1';
    return (res);
}

