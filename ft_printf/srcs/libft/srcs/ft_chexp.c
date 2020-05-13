#include "libft.h"
#include <stdio.h>

char    *ft_chexp(char *str, size_t n)
{
    char    *res;
    char    *buf;

    if (n == 0)
        return ("1.0");
    res = ft_strdup(str);
    while (n-- > 1) {
        buf = res;
        res = ft_chmult(res, str);
        free(buf);
    }
    return (res);
}

