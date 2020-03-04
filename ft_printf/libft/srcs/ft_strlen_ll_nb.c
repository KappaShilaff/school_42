#include "libft.h"

int     ft_strlen_ll_nb(long long int nb)
{
    int     i;

    i = 0;
    if (nb < 0) {
        nb *= -1;
        i++;
    }
    while (nb > 0)
    {
        i++;
        nb /= 10;
    }
    return (i);
}