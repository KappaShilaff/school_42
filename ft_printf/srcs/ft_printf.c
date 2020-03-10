#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

//void    ft_sstar(va_list arg, char *str)
//{
//    int     i;
//    int     k;
//    char    *out;
//    char    minus;
//    char    plus;
//    char    space;
//
//    out = str;
//    minus = '+';
//    plus = '-';
//    space = '\0';
//    while (*str != '*' && (*str == ' ' || *str == '0' || *str == '-' || *str == '+')) {
//        if (*str == '-')
//            minus = '-';
//        if (*str == '+')
//            plus = '+';
//        if (*str == ' ')
//            space = ' ';
//        *str++;
//    }
//    if (*str++ == '*') {
//        if (*str != 's') {
//            write(1, "%", 1);
//            while (*out != 's')
//                write(1, &(*out++), 1);
//            return ;
//        }
//        i = va_arg(arg, int);
//        out = va_arg(arg, char *);
//        k = i - ft_strlen(out);
//        if (minus == '-') {
//            while (*out)
//                write(1, &(*out++), 1);
//            while (k-- > 0)
//                write(1, " ", 1);
//        } else {
//            while (k-- > 0)
//                write(1, " ", 1);
//            while (*out)
//                write(1, &(*out++), 1);
//        }
//    } else {
//        write(1, "%", 1);
//        if (space == ' ' && plus == '+' && minus == '-')
//            write(1, "+-", 2);
//        if (minus == '-' && space == ' ' && plus != '+')
//            write(1, " -", 2);
//        while (*out != '*' && (*out == ' ' || *out == '0' || *out == '-' || *out == '+'))
//                *out++;
//        while (*out != 's')
//            write(1, &(*out++), 1);
//        write(1, "s", 1);
//    }
//}

int     ft_dflag(char *str, va_list arg) {
    char minus;
    char plus;
    int i;
    long long int nb_ll;
    size_t      nb_z;
    int k;
//    char star;
    char *temp;
    char ll = '0';
    char l = '0';
    char h = '0';
    char L = '0';
    char hh = '0';
    char j = '0';
    char z = '0';
    char zero = '1';
    char resh = '1';
    char space = '1';
    char kov = '1';

//    star = '0';
    i = 0;
    minus = '+';
    plus = '-';
    while (*str == ' ' || *str == '+' || *str == '-' || *str == '*' || *str == '0' || *str == 'l' || *str == 'z' ||
           *str == 'h' || *str == 'L' || *str == 'j' || *str == '#' || *str == '\'') {
        if (*str == '-')
            minus = '-';
        if (*str == '\'')
            kov = '\'';
        if (*str == '+')
            plus = '+';
//        if (*str == '*')
//            star = '1';
        if (*str == 'L')
            L = 'L';
        if (*str == '0')
            zero = '0';
        if (*str == 'h') {
            if (*(str + 1) && (*(str + 1) == 'l')) {
                hh = 'h';
                str++;
            } else
                h = 'h';
        }
        if (*str == 'l') {
            if (*(str + 1) && (*(str + 1) == 'l')) {
                ll = 'l';
                str++;
            } else
                l = 'l';
        }
        if (*str == 'j')
            j = 'j';
        if (*str == 'z')
            z = 'z';
        if (*str == '#')
            resh = '#';
        if (*str == ' ')
            space = ' ';
        if (*str != 'd')
            str++;
    }
    temp = str;
    i = ft_atoi(str);
    while (*str >= '0' && *str <= '9')
            str++;
    if (*str != 'd') {
        write(1, "%", 1);
        if (kov == '\'')
            write(1, "'", 1);
        if (resh == '#')
            write(1, "#", 1);
        if (plus == '+')
            write(1, "+", 1);
        else if (space == ' ')
            write(1, " ", 1);
        if (minus == '-')
            write(1, "-", 1);
        else if (zero == '0')
            write(1, "0", 1);
        while (*temp != 'd')
            write(1, &(*temp++), 1);
        write(1, &(*temp), 1);
        return (1);
    }
        i = ft_atoi(temp);
    if (ll == 'l')
        nb_ll = va_arg(arg, long long int);
    else if (l == 'l')
        nb_ll = (long long int) (va_arg(arg, long int));
    else if (z == 'z')
        nb_z = va_arg(arg, size_t);
    else if (h == 'h')
        nb_ll = (long long int) (short int) (va_arg(arg, int));
    else if (hh == 'h')
        nb_ll = (long long int) (unsigned char) (va_arg(arg, int));
    else
        nb_ll = (long long int) (va_arg(arg, long int));
    if (i != 0) {
        if (z != 'z')
            k = i - ft_strlen_ll_nb(nb_ll);
        else
            k = i - ft_strlen_z_nb(nb_z);
        if (minus == '+') {
            if (zero == '1') {
                if (plus == '+') {
                    while (k-- > 1)
                        write(1, " ", 1);
                    write(1, "+", 1);
                    k--;
                } else {
                    if (space == ' ') {
                        write(1, " ", 1);
                        k--;
                    }
                    while (k-- > 0)
                        write(1, " ", 1);
                }
            } else {
                if (plus == '+') {
                    write(1, "+", 1);
                    k--;
                    while (k-- > 0)
                        write(1, "0", 1);

                } else {
                    if (space == ' ') {
                        write(1, " ", 1);
                        k--;
                    }
                    while (k-- > 0)
                        write(1, "0", 1);
                }
            }
            if (z != 'z')
                ft_putnbr(nb_ll);
            else
                ft_putnbr_z_fd(nb_z, 1);
        } else {
            if (plus == '+') {
                write(1, "+", 1);
                k--;
            } else if (space == ' ')
            {
                write(1, " ", 1);
                k--;
            }
            if (z != 'z')
                ft_putnbr(nb_ll);
            else
                ft_putnbr_z_fd(nb_z, 1);
            while (k-- > 0)
                write(1, " ", 1);
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
    char    *temp;
    char    resh;
    char    plus;
    char    space = '1';
    char    zero = '1';
    char    kov = '1';

    temp = str;
    minus = '+';
    resh = '0';
    plus = '-';
    while (*str == '\'' || *str == ' ' || *str == '+' || *str == '-' || *str == '*' || *str == '#' || (*str == 0))
    {
        if (*str == '\'')
            kov = '\'';
        if (*str == '-')
            minus = '-';
        if (*str == '+')
            plus = '+';
        if (*str == ' ')
            space = ' ';
        if (*str == '#')
            resh = '#';
        if (*str == '0')
            zero = '0';
        str++;
    }
    if (*str != 's') {
        write(1, "%", 1);
        if (kov == '\'')
            write(1, "'", 1);
        if (resh == '#')
            write(1, "#", 1);
        if (plus == '+')
            write(1, "+", 1);
        else if (space == ' ')
            write(1, " ", 1);
        if (minus == '-')
            write(1, "-", 1);
        else if (zero == '0')
            write(1, "0", 1);
    }
    if (*str == 'l')
    {
        str++;
        while (*str != 's')
            write(1, &(*str++), 1);
        write(1, &(*str), 1);
        return (1);
    }
    if (*str != 's')
    {
        while (*str != 's')
            write(1, &(*str++), 1);
        write(1, "s", 1);
        return (1);
    }

        while (*temp == '-' || *temp == '+' || *temp == ' ' || *temp == '0' || *temp == '\'' || *temp == '#')
            *temp++;
        i = ft_atoi(temp);
        out = va_arg(arg, char *);
        if (i != 0) {
            k = i - ft_strlen(out);
            if (minus == '+') {
                while (k-- > 0)
                    write(1, " ", 1);
            }
            ft_putstr(out);
            while (k-- > 0)
                write(1, " ", 1);
            return (1);
        } else {
            ft_putstr(out);
            return (1);
        }
    }


char    *ft_flag(char *str, va_list arg) {
    int i;
    int n;
    char   *tmp;

    tmp = str;
    n = 0;
    while (str[n] && ((str[n] != 's') && str[n] != 'd'))
        n++;
    if (!str[n])
        return (tmp + 1);
    if (str[n] == 's'  && !ft_sflag(tmp, arg))
    {
        write(1, "%", 1);
        return (tmp);
    }
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