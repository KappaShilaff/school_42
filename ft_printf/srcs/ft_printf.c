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

void    ft_fill_struct(struct s_part *this)
{
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
}

int     ft_dflag(char *str, struct s_part *part) {
    long long int nb_ll = 0;
    size_t nb_z = 0;
    int k;
    int p;
    char *temp;

    k = 0;
    p = 0;
    while (*str == ' ' || *str == '+' || *str == '-' || *str == '*' || *str == '0' || *str == 'l' || *str == 'z' ||
           *str == 'h' || *str == 'L' || *str == 'j' || *str == '#' || *str == '\'' || *str == '.') {
        if (*str == '-')
            part->minus = 1;
        if (*str == '\'')
            part->quot = 1;
        if (*str == '+')
            part->plus = 1;
        if (*str == 'L')
            part->L = 1;
        if (*str == '0')
            part->zero = 1;
        if (*str == 'h') {
            if (*(str + 1) && (*(str + 1) == 'h')) {
                part->hh = 1;
                str++;
            } else
                part->h = 1;
        }
        if (*str == 'l') {
            if (*(str + 1) && (*(str + 1) == 'l')) {
                part->ll = 1;
                str++;
            } else
                part->l = 1;
        }
        if (*str == 'j')
            part->j = 1;
        if (*str == 'z')
            part->z = 1;
        if (*str == '#')
            part->hashtag = 1;
        if (*str == ' ')
            part->space = 1;
        if (*str == '.')
            part->points = 1;
        if (*str != 'd')
            str++;
    }
    temp = str;
    if (part->points == 0)
        part->i = ft_atoi(str);
    else
        p = ft_atoi(str);
    while (*str >= '0' && *str <= '9')
        str++;
    if (*str == '.') {
        part->points = 1;
        part->zero = 0;
        str++;
        p = ft_atoi(str);
        while (*str >= '0' && *str <= '9')
            str++;
        if (*str != 'd')
        {
            write(ft_int_out(part, 1), "%", 1);
            while(*temp != 'd')
                write(ft_int_out(part, 1), &(*temp++), 1);
            write(ft_int_out(part, 1), &(*temp), 1);
            return (1);
        }
    }
    if (*str != 'd') {
        write(ft_int_out(part, 1), "%", 1);
        if (part->points == 1)
            write(ft_int_out(part, 1), ".", 1);
        if (part->quot == 1)
            write(ft_int_out(part, 1), "'", 1);
        if (part->hashtag == 1)
            write(ft_int_out(part, 1), "#", 1);
        if (part->plus == 1)
            write(ft_int_out(part, 1), "+", 1);
        else if (part->space == 1)
            write(ft_int_out(part, 1), " ", 1);
        if (part->minus == 1)
            write(ft_int_out(part, 1), "-", 1);
        else if (part->zero == 1)
            write(ft_int_out(part, 1), "0", 1);
        while (*temp != 'd')
            write(ft_int_out(part, 1), &(*temp++), 1);
        write(ft_int_out(part, 1), &(*temp), 1);
        return (1);
    }
    part->i = ft_atoi(temp);
    if (part->ll == 1 || part->j == 1)
        nb_ll = va_arg(*part->arg, long long int);
    else if (part->l == 1)
        nb_ll = (long long int)(va_arg(*part->arg, long int));
    else if (part->z == 1)
        nb_z = va_arg(*part->arg, size_t);
    else if (part->h == 1)
        nb_ll = (long long int)(short int)(va_arg(*part->arg, int));
    else if (part->hh == 1)
        nb_ll = (long long int)(char)(va_arg(*part->arg, int));
    else
        nb_ll = (long long int)(va_arg(*part->arg, int));
    if (part->points == 1 && nb_ll < 0)
        p++;
    if (part->i != 0) {
        if (part->z == 0) {
            if (p != 0)
                p -= ft_strlen_ll_nb(nb_ll);
            k = part->i  - p - ft_strlen_ll_nb(nb_ll);
            if (part->points == 1 && nb_ll == 0) {
                if (p == 0)
                    k++;
                else
                    p++;
            }
        } else {
            if (p != 0)
                p -= ft_strlen_z_nb(nb_z);
            k = part->i - p - ft_strlen_z_nb(nb_z);
            if (part->points == 1 && nb_z == 0) {
                if (p == 0)
                    k++;
                else
                    p++;
            }
        }
        if (part->minus == 0) {
            if (part->zero == 0) {
                if (part->plus == 1 && (part->z == 1 || nb_ll >= 0)) {
                    while (k-- > 1)
                        write(ft_int_out(part, 1), " ", 1);
                    write(ft_int_out(part, 1), "+", 1);
                } else {
                    if (part->space == 1 && (part->z == 1 || nb_ll >= 0)) {
                        write(ft_int_out(part, 1), " ", 1);
                        k--;
                    }
                    while (k-- > 0)
                        write(ft_int_out(part, 1), " ", 1);
                    if (part->points == 1 && nb_ll < 0) {
                        write(ft_int_out(part, 1), "-", 1);
                        nb_ll *= -1;
                    }
                }
                if (part->z == 0) {
                    while (p-- > 0)
                        write(ft_int_out(part, 1), "0", 1);
                    if (!(part->points == 1 && nb_ll == 0)) {
                        ft_int_out(part, ft_strlen_ll_nb(nb_ll));
                        ft_putnbr(nb_ll);
                    }
                } else {
                    while (p-- > 0)
                        write(ft_int_out(part, 1), "0", 1);
                    if (!(part->points == 1 && nb_ll == 0)) {
                        ft_int_out(part, ft_strlen_ll_nb(nb_z));
                        ft_putnbr_z_fd(nb_z, 1);
                    }
                }
            } else {
                if (part->z == 0 && nb_ll < 0) {
                    write(ft_int_out(part, 1), "-", 1);
                    nb_ll *= -1;
                    part->negative = 1;
                }
                if (part->plus == 1 && (part->z == 1 || nb_ll >= 0)) {
                    if (part->negative == 0) {
                        write(ft_int_out(part, 1), "+", 1);
                        k--;
                    }
                    while (k-- > 0)
                        write(ft_int_out(part, 1), "0", 1);
                } else {
                    if (part->space == 1) {
                        write(ft_int_out(part, 1), " ", 1);
                        k--;
                    }
                    while (k-- > 0)
                        write(ft_int_out(part, 1), "0", 1);
                }

                if (part->z == 0) {
                    while (p-- > 0)
                        write(ft_int_out(part, 1), "0", 1);
                    if (!(part->points == 1 && nb_ll == 0)) {
                        ft_int_out(part, ft_strlen_ll_nb(nb_ll));
                        ft_putnbr(nb_ll);
                    }
                } else {
                    while (p-- > 0)
                        write(ft_int_out(part, 1), "0", 1);
                    if (!(part->points == 1 && nb_ll == 0)) {
                        ft_int_out(part, ft_strlen_ll_nb(nb_z));
                        ft_putnbr_z_fd(nb_z, 1);
                    }
                }
            }
        } else {
            if (part->plus == 1 && (part->z == 1 || nb_ll >= 0)) {
                write(ft_int_out(part, 1), "+", 1);
                k--;
            } else if (part->space == 1 && (part->z == 1 || nb_ll >= 0)) {
                write(ft_int_out(part, 1), " ", 1);
                k--;
            }
            if (part->z == 0) {
                while (p-- > 0)
                    write(ft_int_out(part, 1), "0", 1);
                if (!(part->points == 1 && nb_ll == 0)) {
                    ft_putnbr(nb_ll);
                    ft_int_out(part, ft_strlen_ll_nb(nb_ll));
                }
            } else {
                while (p-- > 0)
                    write(ft_int_out(part, 1), "0", 1);
                if (!(part->points == 1 && nb_ll == 0)) {
                    ft_putnbr_z_fd(nb_z, 1);
                    ft_int_out(part, ft_strlen_ll_nb(nb_z));
                }
            }
            while (k-- > 0)
                write(ft_int_out(part, 1), " ", 1);
            return (1);
        }
    } else {
        if (part->plus == 1 && (part->z == 1 || nb_ll >= 0)) {
            write(ft_int_out(part, 1), "+", 1);
            k--;
        } else if (part->space == 1 && (part->z == 1 || nb_ll >= 0)) {
            write(ft_int_out(part, 1), " ", 1);
            k--;
        }
        if (part->z == 0) {
            while (p-- > 0)
                write(ft_int_out(part, 1), "0", 1);
            if (!(part->points == 1 && nb_ll == 0)) {
                ft_putnbr(nb_ll);
                ft_int_out(part, ft_strlen_ll_nb(nb_ll));
            }
        } else {
            while (p-- > 0)
                write(ft_int_out(part, 1), "0", 1);
            if (!(part->points == 1 && nb_ll == 0)) {
                ft_putnbr_z_fd(nb_z, 1);
                ft_int_out(part, ft_strlen_ll_nb(nb_z));
            }
        }
        while (k-- > 0)
            write(ft_int_out(part, 1), " ", 1);
        return (1);
    }
    return (1);
}

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
    if (*str == 'l')
    {
        write(ft_int_out(part, 1), "%", 1);
        if (part->quot == 1)
            write(ft_int_out(part, 1), "'", 1);
        if (part->hashtag == 1)
            write(ft_int_out(part, 1), "#", 1);
        if (part->plus == 1)
            write(ft_int_out(part, 1), "+", 1);
        else if (part->space == 1)
            write(ft_int_out(part, 1), " ", 1);
        if (part->minus == 1)
            write(ft_int_out(part, 1), "-", 1);
        else if (part->zero == 1)
            write(ft_int_out(part, 1), "0", 1);
        str++;
        while (*str != 's')
            write(ft_int_out(part, 1), &(*str++), 1);
        write(ft_int_out(part, 1), &(*str), 1);
        return (1);
    }
    if (*str != 's' && (*str <= '0' || *str >= '9')) {
        write(ft_int_out(part, 1), "%", 1);
        if (part->quot == 1)
            write(ft_int_out(part, 1), "'", 1);
        if (part->hashtag == 1)
            write(ft_int_out(part, 1), "#", 1);
        if (part->plus == 1)
            write(ft_int_out(part, 1), "+", 1);
        else if (part->space == 1)
            write(ft_int_out(part, 1), " ", 1);
        if (part->minus == 1)
            write(ft_int_out(part, 1), "-", 1);
        else if (part->zero == 1)
            write(ft_int_out(part, 1), "0", 1);
        while (*str != 's')
            write(ft_int_out(part, 1), &(*str++), 1);
        write(ft_int_out(part, 1), "s", 1);
        return (1);
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
            if (part->minus == 0) {
                while ((part->k)-- > 0)
                    write(ft_int_out(part, 1), " ", 1);
            }
            write(ft_int_out(part, part->obj), out, part->obj);
            while ((part->k)-- > 0)
                write(ft_int_out(part, 1), " ", 1);
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

char    *ft_flag(char *str, struct s_part *part) {

    ft_fill_struct(part);
    part->format = str;
    while (str[part->n] && ((str[part->n] != 's') && str[part->n] != 'd'))
        (part->n)++;
    if (!str[part->n])
        return (part->format + 1);
    if (str[part->n] == 's'  && !ft_sflag(part->format, part))
    {
        write(1, "%", 1);
        (part->int_out)++;
        return(part->format);
    }
    if (str[part->n] == 'd'  && !ft_dflag((part->format), part))
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
    return (part.int_out);
}