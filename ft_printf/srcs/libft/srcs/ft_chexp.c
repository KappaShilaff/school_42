#include "libft.h"
#include <stdio.h>

//char    *ft_chexp(char *str, size_t n)
//{
//    char    *res;
//    char    *buf;
//
//    if (n == 0)
//        return ("1.0");
//    res = ft_strdup(str);
//    while (n-- > 1) {
//        buf = res;
//        res = ft_chmult(res, str);
//        free(buf);
//    }
//    return (res);
//}

char    *ft_chexp(char *str, size_t n)
{
    char    *res;
    char    *buf;
    char    *value;

    value = ft_strdup(str);
    if (n == 0)
        return ("1.0");
    res = ft_strdup("1.0");
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            buf = res;
            res = ft_chmult(res, value);
            free(buf);
        }
        buf = value;
        value = ft_chmult(value, value);
        free(buf);
        n /= 2;
    }
    free(value);
    return (res);
}

