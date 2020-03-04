#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

void    ft_sstar(va_list arg, char *str)
{
    int     i;
    int     k;
    char    *out;
    char    minus;
    char    plus;
    char    space;

    out = str;
    minus = '+';
    plus = '-';
    space = '\0';
    while (*str != '*' && (*str == ' ' || *str == '0' || *str == '-' || *str == '+')) {
        if (*str == '-')
            minus = '-';
        if (*str == '+')
            plus = '+';
        if (*str == ' ')
            space = ' ';
        *str++;
    }
    if (*str++ == '*') {
        if (*str != 's') {
            write(1, "%", 1);
            while (*out != 's')
                write(1, &(*out++), 1);
            return ;
        }
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
    } else {
        write(1, "%", 1);
        if (space == ' ' && plus == '+' && minus == '-')
            write(1, "+-", 2);
        if (minus == '-' && space == ' ' && plus != '+')
            write(1, " -", 2);
        while (*out != '*' && (*out == ' ' || *out == '0' || *out == '-' || *out == '+'))
                *out++;
        while (*out != 's')
            write(1, &(*out++), 1);
        write(1, "s", 1);
    }
}

int     ft_dflag(char *str, va_list arg)
{
    char    minus;
    int     i;
    char    *out;
    int     k;
    char    star;
    char    *temp;
    char    ll = '0';
    char    l = '0';
    char    h = '0';
    char    L = '0';
    char    hh = '0';
    char    j = '0';
    char    z = '0';

    temp = str;
    star = '0';
    i = 0;
    minus = '+';
    while (*str == ' ' || *str == '+' || *str == '-' || *str == '*' || (*str >= '0' && *str <= '9') || *str == 'l' || *str == 'z' || *str == 'h' || *str == 'L' || *str == 'j')
    {
        if (*str == '-')
            minus = '-';
        if (*str == '*')
            star = '1';
        if (*str == 'L')
            L = 'L';
        if (*str == 'h') {
            if (*(str + 1) == 'l') {
                hh = 'h';
                *str++;
            } else
                h = 'h';
        }
        if (*str == 'l') {
            if (*(str + 1) == 'l') {
                ll = 'l';
                *str++;
            } else
                l = 'l';
        }
        if (*str == 'j')
            j = 'j';
        if (*str == 'z')
            z = 'z';
        *str++;
    }
    if (*str != 'd')
        return (0);
    if (star == '1')
    {
        i = va_arg(arg, int);
        return (1);
    }
    else {
        while (*temp == '-' || *temp == '+' || *temp == ' ' || *temp == '0')
            *temp++;
        i = ft_atoi(temp);
    }
//  napisat' CASE l L ll h hh z j dlya va_arg a ewe napisat' strlen dlya chisel chtob virovnyalka rabotala ny i kone4no putnbr dlya vseh types
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
            return (1);
        } else {
            while (*out)
                write(1, &(*out++), 1);
            return (1);
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
    while (*str == ' ' || *str == '+' || *str == '-' || *str == '*' || (*str >= '0' && *str <= '9'))
    {
        if (*str == '-')
            minus = '-';
        if (*str == '*')
            star = '1';
        *str++;
    }
    if (*str != 's')
        return (0);
    if (star == '1')
    {
        ft_sstar(arg, temp);
        return (1);
    } else {
//        printf("\n%s\n", temp);
        while (*temp == '-' || *temp == '+' || *temp == ' ' || *temp == '0')
            *temp++;
        i = ft_atoi(temp);
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
            return (1);
        } else {
            while (*out)
                write(1, &(*out++), 1);
            return (1);
        }
    }
}

char    *ft_flag(char *str, va_list arg) {
    int i;
    int n;
    char   *tmp;

    tmp = str;
    n = 0;
    while (str[n] && ((str[n] != 's') || str[n] != 'd'))
        n++;
    if (!str[n])
        return (tmp + 1);
    if (str[n] == 's'  && !ft_sflag(tmp, arg))
        return (tmp + 1);
    if (str[n] == 'd'  && !ft_dflag(tmp, arg))
        return (tmp + 1);
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