#include "get_next_line.h"
#include <stdio.h>

t_node	*ft_find_node(t_node *list, int fd)
{
	t_node	*tmp;
	t_cont	*cont;

	if (!list)
		return (NULL);
	tmp = list;
	cont = tmp->d;
	while (cont->fd != fd && tmp)
	{
		if (cont->fd > fd)
			tmp = tmp->l;
		else
			tmp = tmp->r;
		if (tmp)
			cont = tmp->d;
	}
	return (tmp);
}

t_cont	*ft_create_cont(int fd, char *str)
{
	t_cont	*t;

	if (!(t = malloc(sizeof(t_node))))
		return(NULL);
	t->fd = fd;
	t->str = str;
	t->end = 0;
	return (t);
}

int		ft_cmp(t_cont a, t_cont b)
{
	if (a.fd > b.fd)
		return (1);
	else
		return (-1);
}

char	*ft_str(t_node *t, int fd)
{
	char	*str;
	char	*lol;
	char	*tmp;
	char	*tmpjoin;
	size_t	len[2];
	
	if (((t_cont *)(t->d))->str == NULL)
	{
		str = ft_chmalloc_zend(BUFF_SIZE + 1);
		if (!(len[1] = (read(fd, str, BUFF_SIZE))))
		{
			free(str);
			return (NULL);
		}
		str[len[1]] = '\0';
	}
	else
		str = ((t_cont *)(t->d))->str;
	tmpjoin = ft_chmalloc_zend(BUFF_SIZE);
	while (!(ft_strchr(str, '\n')))
	{
		if (!(len[1] = (read(fd, tmpjoin, BUFF_SIZE))))
		{
			str -= (((t_cont *)(t->d))->end);
			free(str);
			free(tmpjoin);
			return (NULL);
		}
		lol = str;
		str = ft_strjoin(lol, tmpjoin);
		free(lol -= (((t_cont *)(t->d))->end));
		((t_cont *)(t->d))->end = 0;
	}
	len[0] = ft_findchr(str, '\n');
	tmp = ft_chmalloc_zend(len[0]);
	ft_strncpy(tmp, str, len[0]++);
	((t_cont *)(t->d))->end += len[0];
	((t_cont *)(t->d))->str = (str += len[0]);
	free(tmpjoin);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_node	*head;
	t_node			*curr;

	if (fd == -1)
		return (-1);
	if (!(curr = ft_find_node(head, fd)))
		curr = ft_create_node(ft_create_cont(fd, NULL));
	if (!head)
		head = ft_insert_node(head, curr, (void *)ft_cmp);
	if ((*line = ft_str(curr, fd)) != NULL)
		return (1);
	return (0);
}
