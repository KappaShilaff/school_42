#include "libft.h"
#include "librb.h"

int		ft_free_cont(t_cont *t)
{
	int	fd;

	fd = t->fd;
	ft_bzero(t, sizeof(t_cont));
	t->fd = fd;
	return (0);
}
