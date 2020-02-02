#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

void    ft_fstar(va_list arg, char *str)
{
    int     i;
    int     k;
    char    *out;
    char    minus;

    minus = '+';
    while (*str == '0' || *str == ' ' || *str == '+' || *str == '-') {
        if (*str == '-')
            minus = '-';
        *str++;
    }
    if (*str == '*') {

        i = va_arg(arg, int);
        out = va_arg(arg, char *);
        k = i - ft_strlen(out);
        if (minus == '-') {
            while (*out)
                write(1, &(*out++), 1);
            while (k-- > 0)
                write(1, " ", 1);
        } else {
            while (k-- > 0)
                write(1, " ", 1);
            while (*out)
                write(1, &(*out++), 1);
        }
    }
}

int     ft_sflag(char *str, va_list arg)
{
    char    minus;
    int     i;
    char    *out;
    int     k;
    char    star;
    char    *temp;

    temp = str;
    star = '0';

    i = 0;
    minus = '+';
    while (*str == ' ' || *str == '+' || *str == '-' || *str == '0' || *str == '*')
    {
        if (*str == '-')
            minus = '-';
        if (*str == '*')
            star = '1';
        *str++;
    }
    if (star == '1')
    {
        ft_fstar(arg, temp);
    } else {
        i = ft_atoi(str);
        out = va_arg(arg, char *);
        if (i != 0) {
            k = i - ft_strlen(out);
            if (minus == '+') {
                while (k-- > 0)
                    write(1, " ", 1);
            }
            while (*out)
                write(1, &(*out++), 1);
            while (k-- > 0)
                write(1, " ", 1);
        } else {
            while (*out)
                write(1, &(*out++), 1);
        }
    }
}

char    *ft_flag(char *str, va_list arg) {
    int i;
    int n;
    char   *tmp;

    tmp = str;
    n = 0;
    while (str[n] && (str[n] == ' ' || str[n] == '+' || str[n] == '-' || str[n] == '0' || str[n] == '*'))
        n++;
    if (!str[n])
        return (tmp + 1);
    while (str[n] >= '0' && str[n] <= '9')
        n++;
    if (!str[n])
        return (tmp + 1);
    if (str[n] == 's')
        ft_sflag(tmp, arg);
    else
        return (0);
    return (tmp + n + 1);
}

int		ft_printf(const char *format, ...)
{
    va_list arg;
    int i;

    va_start(arg, format);
    while (*format) {
        if (*format == '%') {
            *format++;
            format = ft_flag((char *)format, arg);
        }
        if (*format && *format != '%')
            write(1, &(*format++), 1);
    }
    return (0);
}