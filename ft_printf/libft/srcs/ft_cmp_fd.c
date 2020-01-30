#include "libft.h"
#include "librb.h"

int     ft_cmp_fd(t_cont a, t_cont b)
{
    if (a.fd > b.fd)
        return (1);
    else
        return (-1);
}
