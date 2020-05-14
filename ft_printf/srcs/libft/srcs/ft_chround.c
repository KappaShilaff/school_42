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

static void norme1(int i[1], int k[1], int n[1], char **str)
{
    char    *buf;

    i[0] = 0;
    k[0] = 0;
    while ((*str)[i[0]] && (*str)[i[0]] != '.')
        i[0]++;
    if (i[0] + n[0] + 1 < (int)ft_strlen(*str))
        if ((*str)[i[0] + n[0] + 1] >= '4'  && (*str)[i[0] + n[0] + 1] <= '9')
        {
            buf = zeronum(n[0]);
            *str = ft_chsum(*str, buf);
            free(buf);
            k[0] = 1;
        }
}

char    *ft_chround(char *str, int n)
{
    char    *res;
    int     i;
    int     size;
    int     k;

    norme1(&i, &k, &n, &str);
    res = ft_chmalloc_zend(i + n + 1);
    size = i + n;
    i = 0;
    while ((size-- >= 0) && str[i])
    {
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