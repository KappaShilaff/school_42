#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H
# include <stdarg.h>

typedef struct s_part
{
    va_list *arg;
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
    int     obj;
    char    L;
    char    hh;
    char    h;
    char    j;
    char    z;
    char    *format;
    char    negative;
    char    points;
}   t_part;

int				ft_printf(const char *format, ...);

#endif
