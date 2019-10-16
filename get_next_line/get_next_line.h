#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# include "librb.h"

typedef struct	s_cont
{
	int		fd;
	char	*str;
}				t_cont;

int		get_next_line(const int fd, char **line);
t_cont	*ft_create_cont(int fd, char *str);

#endif
