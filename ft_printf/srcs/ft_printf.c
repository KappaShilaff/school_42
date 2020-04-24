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

void    ft_dnumber(struct s_part *part)
{
    if (part->ll == 1)
        part->nb_ll = va_arg(*part->arg, long long int);
    else if (part->l == 1)
        part->nb_ll = va_arg(*part->arg, long int);
    else if (part->h == 1)
        part->nb_ll = (long long int)(short int)(va_arg(*part->arg, int));
    else if (part->hh == 1)
        part->nb_ll = (long long int)(char)(va_arg(*part->arg, int));
    else
        part->nb_ll = (long long int)(va_arg(*part->arg, int));

    if (part->nb_ll < 0) {
        part->negative = 1;
        part->plus = 0;
        part->space = 0;
        part->len = -1;
    }
    if (part->points == 1)
        part->zero = 0;
    if (part->plus == 1)
        part->space = 0;
    part->len += ft_strlen_ll_nb(part->nb_ll);
    part->num = ft_itoa(part->nb_ll);
    if (part->negative == 1)
        (part->num)++;
    if (part->points == 1 && part->nb_ll == 0)
        part->len -= 1;
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

int     ft_part_minus(struct s_part *part)
{
    if (part->negative == 1)
        write(ft_int_out(part, 1), "-", 1);
    if (part->plus == 1)
        write(ft_int_out(part, 1), "+", 1);
    if (part->space == 1)
        write(ft_int_out(part, 1), " ", 1);
    if (part->size > part->len)
        ft_filler(part, part->size - part->len, '0');
    write(ft_int_out(part, part->len), part->num, part->len);
    if (part->field >= part->size)
        ft_filler(part, part->field - part->size, ' ');
    return (1);
}

int     ft_ox_part_minus(struct s_part *part, char type)
{
    if (part->hashtag == 1 ) {
        if (type == 'x')
            write(ft_int_out(part, 2), "0x", 2);
        if (type == 'X')
            write(ft_int_out(part, 2), "0X", 2);
        if (type == 'o')
            write(ft_int_out(part, 1), "0", 1);
    }
    if (part->size > part->len)
        ft_filler(part, part->size - part->len, '0');
    if (part->len != 0) {
        ft_putstr(part->number);
        ft_int_out(part, part->len);
    }
    if (part->field >= part->size)
        ft_filler(part, part->field - part->size, ' ');
    return (1);
}

int     ft_part_nominus(struct s_part *part)
{
    if (part->negative == 1 && part->zero == 1)
        write(ft_int_out(part, 1), "-", 1);
    if (part->plus == 1 && part->zero == 1)
        write(ft_int_out(part, 1), "+", 1);
    if (part->zero == 1)
        ft_filler(part, part->field - part->size, '0');
    else
        ft_filler(part, part->field - part->size, ' ');
    if (part->negative == 1 && part->zero == 0)
        write(ft_int_out(part, 1), "-", 1);
    if (part->plus == 1 && part->zero == 0)
        write(ft_int_out(part, 1), "+", 1);
    if (part->space == 1)
        write(ft_int_out(part, 1), " ", 1);
    if (part->size > part->len)
        ft_filler(part, part->size - part->len, '0');
    write(ft_int_out(part, part->len), part->num, part->len);
    return (1);
}

int     ft_ox_part_nominus(struct s_part *part, char type)
{
    if (part->zero == 0)
        ft_filler(part, part->field - part->size, ' ');
    if (part->hashtag == 1) {
        if (type == 'x')
            write(ft_int_out(part, 2), "0x", 2);
        if (type == 'X')
            write(ft_int_out(part, 2), "0X", 2);
        if (type == 'o')
            write(ft_int_out(part, 1), "0", 1);
    }
    if (part->zero == 1)
        ft_filler(part, part->field - part->size, '0');
    ft_filler(part, part->size - part->len, '0');
    if (part->len != 0) {
        ft_putstr(part->number);
        ft_int_out(part, part->len);
    }
    return (1);
}

void    ft_oxnumber(struct s_part *part, char type)
{
    if (part->ll == 1 || part->l == 1)
        part->nb_z = va_arg(*part->arg, unsigned long int);
    else
        part->nb_z = (unsigned long int)va_arg(*part->arg, unsigned int);
    if (type == 'x' || type == 'X')
        part->number = ft_unsigned_itoa_base(part->nb_z, 16, type);
    else
        part->number = ft_unsigned_itoa_base(part->nb_z, 8, 'X');
    part->len = ft_strlen(part->number);
    if (part->nb_z == 0) {
        if (part->hashtag == 1)
            part->nb_ll = 1;
        part->hashtag = 0;
    }
    if (part->hashtag == 1) {
        if (type == 'x' || type == 'X')
            part->field -= 2;
        else
            part->field -= 1;
    }
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

int     ft_oxflag(char *str, struct s_part *part, char type)
{
    ft_parsing(part, &str, type);
    ft_oxnumber(part, type);
    if (!(part->nb_ll == 1 && type == 'o' && part->nb_z == 0 && part->size == 0))
        if (part->size == 0 && part->points == 1 && part->nb_z == 0)
            part->len = 0;
    if (part->len > part->size)
        part->size = part->len;
    if (part->size > part->field)
        part->field = part->size;
    if (part->minus == 1)
        return (ft_ox_part_minus(part, type));
    return (ft_ox_part_nominus(part, type));
}

int     ft_perflag(char *str, struct s_part *part)
{
    while (*str == '.' || *str == '\'' || *str == ' ' || *str == '+' || *str == '-' || *str == '*' || *str == '#' || (*str == '0'))
            str++;
    while (*str >= '0' && *str <= '9')
        str++;
    if (*str == '.') {
        str++;
        while (*str >= '0' && *str <= '9')
            str++;
    }
    write(ft_int_out(part, 1), "%", 1);
    return (1);
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
    out = (char)va_arg(*part->arg, char *);
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

int     ft_dflag(char *str, struct s_part *part, char type) {
    ft_parsing(part, &str, type);
    ft_dnumber(part);
    if (part->negative == 1 || part->plus == 1 || part->space == 1)
        part->field -= 1;
    if (part->len > part->size)
        part->size = part->len;
    if (part->size > part->field)
        part->field = part->size;
    if (part->minus == 1)
        return (ft_part_minus(part));
    return (ft_part_nominus(part));
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