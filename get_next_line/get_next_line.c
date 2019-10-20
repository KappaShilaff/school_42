#include "get_next_line.h"
#include <stdio.h>

int		ft_join(t_cont *t, int fd)
{
	size_t	len;
	char	*lol;
	char	*tmpjoin;

	tmpjoin = ft_chmalloc_zend(BUFF_SIZE);
	while (!(ft_findchr(t->str, '\n')))
    {   
        if (!(len = (read(fd, tmpjoin, BUFF_SIZE))))
        {   
            free(tmpjoin);
            return (-1);
        }   
        tmpjoin[len] = '\0';
        lol = t->str;
        t->str = ft_strjoin(lol, tmpjoin);
        free(lol - (t->end));
        t->end = 0;
    }
	free(tmpjoin);
	return (1);
} 

char	*ft_str(t_cont *t, int fd)
{
	char	*tmp;
	size_t	len[2];
	
	if ((t->str == NULL))
	{
		t->str = ft_chmalloc_zend(BUFF_SIZE);
		if (!(len[1] = (read(fd, t->str, BUFF_SIZE))))
            return (NULL);
		(t->str)[len[1]] = '\0';
	}
	if (ft_join(t, fd) == -1)
	{
		tmp = ft_strdup(t->str);
		free(t->str - t->end);
		t->str = NULL;
		return (tmp);
	}
	len[0] = ft_findchr(t->str, '\n');
	tmp = ft_chmalloc_zend(len[0]);
	ft_strncpy(tmp, t->str, len[0]++);
	t->end += len[0];
	t->str += len[0];
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_node	*head;
	t_node			*curr;

	if (read(fd, 0, 0) == -1)
		return (-1);
	if (!(curr = ft_find_node_fd(head, fd)))
		curr = ft_create_node(ft_create_cont_fd(fd, NULL));
	if (!head)
		head = ft_insert_node(head, curr, (void *)ft_cmp_fd);
	if ((*line = ft_str(((t_cont *)(curr->d)), fd)) != NULL)
		return (1);
	return (0);
}
