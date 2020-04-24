#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int     ft_sflag(char *str, struct s_part *part)
{
    char    *out;
    char    *temp;

    temp = str;
    while (*str == '.' || *str == '\'' || *str == ' ' || *str == '+' || *str == '-' || *str == '*' || *str == '#' || (*str == '0'))
    {
        if (*str == '\'')
            part->quot = 1;
        if (*str == '-')
            part->minus = 1;
        if (*str == '+')
            part->plus = 1;
        if (*str == ' ')
            part->space = 1;
        if (*str == '#')
            part->hashtag = 1;
        if (*str == '0')
            part->zero = 1;
        if (*str == '.') {
            part->point = 1;
            part->obj = ft_atoi(str + 1);
        }
        str++;
    }
    while (*temp == '-' || *temp == '+' || *temp == ' ' || *temp == '0' || *temp == '\'' || *temp == '#')
        temp++;
    if (part->point == 0)
        part->field = ft_atoi(temp);
    while (*temp >= '0' && *temp <= '9')
        temp++;
    out = va_arg(*part->arg, char *);
    if (*temp == '.') {
        part->obj = ft_atoi(temp + 1);
        if (part->obj > ft_strlen(out))
            part->obj = ft_strlen(out);
    }
    if (out == NULL) {
        write(ft_int_out(part, 6), "(null)", 6);
        return (1);
    }
    if (part->field != 0) {
        if (part->obj == 0)
            part->obj = ft_strlen(out);
        part->k = part->field - part->obj;
        if (part->minus == 0)
            part->k = ft_filler(part, (long int)(part->k), ' ');
        write(ft_int_out(part, part->obj), out, part->obj);
        part->k = ft_filler(part, (long int)(part->k), ' ');
        return (1);
    } else {
        if (part->obj == 0) {
            ft_putstr(out);
            ft_int_out(part, ft_strlen(out));
        } else {
            if (part->obj > ft_strlen(out))
                part->obj = ft_strlen(out);
            write(ft_int_out(part, part->obj), out, part->obj);
        }
        return (1);
    }
}

int     ft_cflag(char *str, struct s_part *part)
{
    char    out;
    char    *temp;

    temp = str;
    while (*str == '.' || *str == '\'' || *str == ' ' || *str == '+' || *str == '-' || *str == '*' || *str == '#' || (*str == '0'))
    {
        if (*str == '\'')
            part->quot = 1;
        if (*str == '-')
            part->minus = 1;
        if (*str == '+')
            part->plus = 1;
        if (*str == ' ')
            part->space = 1;
        if (*str == '#')
            part->hashtag = 1;
        if (*str == '0')
            part->zero = 1;
        str++;
    }
    part->field = ft_atoi(temp);
    while (*temp >= '0' && *temp <= '9')
        temp++;
    out = va_arg(*part->arg, int);
    if (*temp == '.') {
        temp++;
        while (*temp >= '0' && *temp <= '9')
            temp++;
    }
    if (part->field == 0 || part->field == 1 || part->field == -1)
        write(ft_int_out(part, 1), &out, 1);
    else {
        if (part->field < 0) {
            write(ft_int_out(part, 1), &out, 1);
            ft_filler(part, (long int)(part->field * -1 - 1), ' ');
        } else {
            ft_filler(part, (long int)(part->field - 1), ' ');
            write(ft_int_out(part, 1), &out, 1);
        }
    }
    return (1);
}