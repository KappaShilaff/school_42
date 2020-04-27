#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void    ft_pnumber(struct s_part *part, char type)
{
    part->nb_z = va_arg(*part->arg, unsigned long int);
    if (part->nb_z == 0)
        return ;
    part->number = ft_unsigned_itoa_base(part->nb_z, 16, type);
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

int     ft_pflag(char *str, struct s_part *part, char type)
{
    ft_parsing(part, &str, 'p');
    part->hashtag = 1;
    ft_pnumber(part, 'x');
    if (part->nb_z == 0) {
        write(ft_int_out(part, 3), "0x0", 3);
        return (1);
    }
    if (part->len > part->size)
        part->size = part->len;
    if (part->size > part->field)
        part->field = part->size;
    if (part->minus == 1)
        return (ft_ox_part_minus(part, type));
    return (ft_ox_part_nominus(part, type));
}

