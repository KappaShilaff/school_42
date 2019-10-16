#include "get_next_line.h"
#include <stdio.h>

static t_node *head;

char	*ft_mda(char *a, char *b)
{
	char *kek;
	int		i;
	int		k;

	i = 0;
	kek = ft_memalloc(ft_strlen(a) + ft_strlen(b) + 1);
	k = 0;
	while (a[k])
		kek[i++] = a[k++];
	k = 0;
	while (b[k])
		kek[i++] = b[k++];
	kek[i] = '\0';
	return (kek);
}


t_node	*ft_find_node(t_node *list, int fd)
{
	t_node	*tmp;
	t_cont	*cont;

	if (!list)
		return (NULL);
	tmp = list;
	cont = tmp->d;
	//////printf("%i\n", cont->fd);
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
	return (t);
}

int		ft_search_n(char *str)
{
	int	i;
	i = 0;
	//////printf("%i\n", *i);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (i);
	return (0);
}

int		ft_cmp(int a, int b)
{
	if (a > b)
		return (1);
	else
		return (-1);
}

char	*ft_str(t_node *t, int fd)
{
	char	*str;
	int		len;
	char	*tmp;
	char	*tmpjoin;
	
	if (((t_cont *)(t->d))->str == NULL)
	{
		str = ft_strnew(BUFF_SIZE + 1);
		read(fd, str, BUFF_SIZE);
	}
	else
	{
		str = ft_strnew(ft_strlen((((t_cont *)(t->d))->str) + 1));
		str = ((t_cont *)(t->d))->str;
	}
	while ((len = ft_search_n(str)) == 0)
	{
		tmpjoin = ft_strnew(BUFF_SIZE + 1);
		read(fd, tmpjoin, BUFF_SIZE);
		////printf("JOIN %s\n", tmpjoin);
		////printf("JOIN %s\n", str);
		str = ft_mda(str, tmpjoin);
		////printf("STRJOIN %s\n", str);
		ft_strdel(&tmpjoin);
	}
	//printf("LEN %i\n", len);
	//printf("STR %s\n", str);
	tmp = ft_strnew(len + 1);
	ft_strncpy(tmp, str, len);
	len++;
	while (len--)
		str++;
	if (t)
	{
		((t_cont *)(t->d))->str = str;
	}
	//printf("STR NEW %s\n", str);
	//printf("RETURN %s\n", tmp);
	return (tmp);
}

	

int		get_next_line(const int fd, char **line)
{
	t_node			*curr;

	//if (head)
		//printf("HEAD %s\n", ((t_cont *)(head->d))->str);

	if (!(curr = ft_find_node(head, fd)))
	{
		curr = ft_create_node(ft_create_cont(fd, NULL));
		if (head == NULL)
			head = curr;
	} 
	*line = ft_str(curr, fd);
	return (1);
}
