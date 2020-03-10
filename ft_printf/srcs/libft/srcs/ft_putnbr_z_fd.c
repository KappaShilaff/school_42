#include "libft.h"

void	ft_putnbr_z_fd(size_t nb, int fd)
{
    if (nb < 10)
        ft_putchar_fd((nb + 48), fd);
    else
    {
        ft_putnbr_fd((nb / 10), fd);
        ft_putchar_fd((nb % 10 + 48), fd);
    }
}
