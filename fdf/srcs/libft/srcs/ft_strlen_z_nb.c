#include "libft.h"

int     ft_strlen_z_nb(size_t nb)
{
    int     i;

    i = 0;
    if (nb == 0)
        return (1);
    while (nb > 0)
    {
        i++;
        nb /= 10;
    }
    return (i);
}