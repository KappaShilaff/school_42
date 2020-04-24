#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int     ft_int_out(struct s_part *this, int i)
{
    this->int_out += i;
    return(1);
}

int     ft_filler(struct s_part *this, long int i, char k)
{
    char    *out;
    long int    temp;
    if (i <= 0)
        return (0);
    temp = i;
    out = malloc(i + 1);
    while (i-- > 0)
        out[i] = k;
    write(ft_int_out(this, (int)temp), out, temp);
    return (0);
}

void    ft_parsing(struct s_part *part, char **str, char flag)
{
    while (**str == ' ' || **str == '+' || **str == '-'  || (**str >= '0' && **str <= '9') || **str == 'l'  ||
           **str == 'h' || **str == 'j' || **str == '#' || **str == '.') {
        if (**str == '-')
            part->minus = 1;
        if (**str == '+')
            part->plus = 1;
        if (**str == 'L')
            part->L = 1;
        if (**str == '0')
            part->zero = 1;
        if (**str == 'h') {
            if (*(*str + 1) && (*(*str + 1) == 'h')) {
                part->hh = 1;
                (*str)++;
            } else
                part->h = 1;
        }
        if (**str == 'l') {
            if (*(*str + 1) && (*(*str + 1) == 'l')) {
                part->ll = 1;
                (*str)++;
            } else
                part->l = 1;
        }
        if (**str == '#')
            part->hashtag = 1;
        if (**str == ' ')
            part->space = 1;

        if (**str >= '1' && **str <= '9') {
            part->field = ft_atoi(*str);
            while (**str >= '0' && **str <= '9')
                (*str)++;
            (*str)--;
        }
        if (**str == '.') {
            part->points = 1;
            (*str)++;
            part->size = ft_atoi(*str);
            while (**str >= '0' && **str <= '9')
                (*str)++;
        }
        if (**str != flag)
            (*str)++;
    }
}

void    ft_fill_struct(struct s_part *this)
{
    this->len = 0;
    this->d = 0;
    this->hashtag = 0;
    this->k = 0;
    this->i = 0;
    this->l = 0;
    this->ll = 0;
    this->minus = 0;
    this->plus = 0;
    this->zero = 0;
    this->s = 0;
    this->quot = 0;
    this->n = 0;
    this->tmp = NULL;
    this->point = 0;
    this->obj = 0;
    this->field = 0;
    this->L = 0;
    this->hh = 0;
    this->h = 0;
    this->j = 0;
    this->z = 0;
    this->space = 0;
    this->negative = 0;
    this->points = 0;
    this->flags = 0;
    this->nb_ll = 0;
    this->size = 0;
}

char    *ft_flag(char *str, struct s_part *part) {
    ft_fill_struct(part);
    part->format = str;
    while (str[part->n] && ((str[part->n] != 's') && str[part->n] != 'd' && str[part->n] != 'c'
    && str[part->n] != '%' && str[part->n] != 'x') && str[part->n] != 'X' && str[part->n] != 'i' && str[part->n] != 'o'
                                                                                                    && str[part->n] != 'u')
        (part->n)++;
    if (!str[part->n])
        return (part->format + 1);
    if (str[part->n] == 's'  && !ft_sflag(part->format, part))
        return(part->format + 1);
    if (str[part->n] == 'd'  && !ft_dflag((part->format), part, 'd'))
        return (part->format + 1);
    if (str[part->n] == 'c'  && !ft_cflag((part->format), part))
        return (part->format + 1);
    if (str[part->n] == '%'  && !ft_perflag((part->format), part))
        return (part->format + 1);
    if (str[part->n] == 'x'  && !ft_oxflag((part->format), part, 'x'))
        return (part->format + 1);
    if (str[part->n] == 'X'  && !ft_oxflag((part->format), part, 'X'))
        return (part->format + 1);
    if (str[part->n] == 'o'  && !ft_oxflag((part->format), part, 'o'))
        return (part->format + 1);
    if (str[part->n] == 'i'  && !ft_dflag((part->format), part, 'i'))
        return (part->format + 1);
    if (str[part->n] == 'u'  && !ft_uflag((part->format), part))
        return (part->format + 1);
    return (part->format + part->n + 1);
}

int		ft_printf(const char *format, ...)
{
    va_list arg;
    struct s_part part;


    va_start(arg, format);
    part.arg = &arg;
    part.int_out = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            format = ft_flag((char *)format, &part);
        }
        if (*format && *format != '%')
            write(ft_int_out(&part, 1), &(*format++), 1);
    }
    va_end(arg);
    return (part.int_out);
}