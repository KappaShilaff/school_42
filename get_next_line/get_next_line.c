#include "get_next_line.h"
#include <stdio.h>

int		ft_join(t_cont *t, int fd)
{
	char		*join;
	char		*strrm;
	long int	temp;
	long int	temp2;
	long int	temp1;
	long int	temp3;
	int			lol123;

	temp1 = 0;
	temp2 = ft_strlen(t->str);
	t->end = temp2;
	t->tmp = 0;
	if ((temp = ft_findchr(t->str, '\n')) >= 0)
	{
		t->end = temp;
		return (1);
	}
	join = ft_chmalloc_zend(BUFF_SIZE);
	while (1)
	{
		strrm = t->str;
		if (!(temp = read(fd, join, BUFF_SIZE)))
		{
			t->end += temp1 + temp2;
			free(join);
			return (-1);
		}
		join[temp] = '\0';
		if ((temp3 = ft_findchr(join, '\n')) >= 0)
		{
			t->end = temp3 + temp1 + temp2;
			t->str = ft_strjoin(t->str, join);
			t->str[t->end - temp3 + temp] = '\0';
			free(strrm);
			free(join);
			return (1);
		}
		t->str = ft_strjoin(t->str, join);
		free(strrm);
		temp1 += temp;
	}
} 

char	*ft_str(t_cont *t, int fd)
{
	char	*tmp;
	char	*tmprm;
	
	if ((t->str == NULL))
	{
		t->str = ft_chmalloc_zend(BUFF_SIZE);
		if (!(t->end = (read(fd, t->str, BUFF_SIZE))))
            return (NULL);
		(t->str)[t->end] = '\0';
	}
	if (ft_join(t, fd) == -1)
	{
		tmp = ft_strdup(t->str);
		free(t->str);
		t->str = NULL;
		return (tmp);
	}
	tmp = ft_chmalloc_zend(t->end);
	//printf("\n%d\n", t->end);
	ft_strncpy(tmp, t->str, t->end++);
	tmprm = t->str;
	t->str = ft_strdup(t->str += t->end);
	//printf("\n STR : %s\n", t->str);
	free(tmprm);
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
