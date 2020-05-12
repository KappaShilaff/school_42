#include "libft.h"
#include <stdio.h>

static char *zeronum(size_t n)
{
    char    *res;
    size_t     i;

    i = 0;
    n += 2;
    res = ft_chmalloc_zend(n);
    while (i < n)
        res[i++] = '0';
    res[1] = '.';
    res[n - 1] = '1';
    return (res);
}

char    *ft_chround(char *str, size_t n)
{
    char    *res;
    char    *buf;
    size_t     i;
    int     size;
    int     k;

    i = 0;
    k = 0;
    while (str[i] && str[i] != '.')
        i++;
    if (i + n < ft_strlen(str))
        if (str[i + n] >= '4'  && str[i + n] <= '9')
        {
            buf = zeronum(n);
            str = ft_chsum(str, buf);
            free(buf);
            k = 1;
        }
    res = ft_chmalloc_zend(i + n);
    size = i + n;
    i = 0;
    while ((size-- >= 0) && str[i]) {
        res[i] = str[i];
        i++;
    }
    while (size-- >= -1)
        res[i++] = '0';
    if (n == 0)
        res[i - 1] = '\0';
    if (k == 1)
        free(str);
    return (res);
}