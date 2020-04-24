#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_part
{
    va_list *arg;
    int     len;
    long int    nb_ll;
    char    d;
    char    s;
    char    l;
    char    ll;
    char    space;
    char    hashtag;
    char    minus;
    char    plus;
    char    zero;
    char    quot;
    int     i;
    int     k;
    int     n;
    char    *tmp;
    int     int_out;
    char    point;
    int     field;
    int     size;
    int     obj;
    char    L;
    char    hh;
    char    h;
    char    j;
    char    z;
    char    *format;
    char    *num;
    char    negative;
    char    points;
    char    flags;
    char    *number;
    size_t  nb_z;
}   t_part;

int				ft_printf(const char *format, ...);

#endif
