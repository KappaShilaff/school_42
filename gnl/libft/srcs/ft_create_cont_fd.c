#include "libft.h"
#include "librb.h"

t_cont  *ft_create_cont_fd(int fd, char *str)
{
    t_cont  *t; 

    if (!(t = malloc(sizeof(t_cont))))
        return(NULL);
    t->fd = fd;
    t->str = str;
    t->end = 0;
	t->tmp = 0;
    return (t);
}
