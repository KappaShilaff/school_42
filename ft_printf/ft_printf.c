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
    char    zero;
    char    space;

//    printf("\n%s\n", str);
    out = str;
    minus = '+';
    plus = '-';
    zero = '1';
    space = '\0';
    while (*str != '*' && (*str == ' ' || *str == '0' || *str == '-' || *str == '+')) {
        if (*str == '-')
            minus = '-';
        if (*str == '+')
            plus = '+';
        if (*str == '0')
            zero = '0';
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
    while (str[n] && (str[n] != 's'))
        n++;
    if (!str[n])
        return (tmp + 1);
    if (str[n] == 's' && !ft_sflag(tmp, arg))
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