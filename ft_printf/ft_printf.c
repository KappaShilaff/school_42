#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

int     ft_sflag(char *str, va_list *arg)
{
    char    minus;
    int     i;
    char    *out;
    int     k;

    out = va_arg(*arg, char *);
    //printf("%s\n", va_arg(*arg, char *));
    i = 0;
    minus = '+';
    while (*str == ' ' || *str == '+' || *str == '-' || *str == '0')
    {
        if (*str == '-')
            minus = '-';
        *str++;
    }
    i = ft_atoi(str);
    if (i != 0)
    {
        k = i - ft_strlen(out);
        if (minus == '+') {
            while (k-- > 0)
                write(1, " ", 1);
        }
        while (*out)
            write(1, &(*out++), 1);
        while (k-- > 0)
            write(1, " ", 1);
    }
}

char    *ft_flag(char *str, va_list *arg) {
    int i;
    int n;
    char   *tmp;

    tmp = str;
//    printf("%s\n", str);
    n = 0;
    while (str[n] && (str[n] == ' ' || str[n] == '+' || str[n] == '-' || str[n] == '0'))
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

//ft_printnum(const char *str)
//{
//	size_t		i;
//	size_t		n;
//
//	n = 0;
//	i = 0;
//	while (str[i])
//	{
//		if (str[i] = '%' && ft_)
//		{
//			i++;
//			n++;
//		}
//		i++;
//	}
//	return (n);
//}

int		ft_printf(const char *format, ...)
{
    size_t num;
    va_list arg;
    int i;

    format;
//    num = ft_printnum(format);
    va_start(arg, format);
    while (*format) {
        if (*format == '%') {
            *format++;
            format = ft_flag(format, &arg);
        }
        if (*format)
            write(1, &(*format++), 1);
    }
    return (0);
}