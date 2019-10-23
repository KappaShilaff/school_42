#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int		ft_buff_join(size_t buff, t_cont *t, int fd, char *join)
{
	char	*strbuff;
	size_t	i[3];

	i[0] = 0;
	i[1] = buff;
	t->join = NULL;
	strbuff = ft_chmalloc_zend(buff);
	while (buff != 0)
	{
		if (!(i[2] = read(fd, strbuff, BUFF_SIZE)))
		{
			if (i[1] == buff)
			{
				free(strbuff);
				return (-3);
			}
			t->join = strbuff - i[0];
			t->end = i[0];
			return (-2);
		}
		t->len += i[2];
		strbuff[i[2]] = '\0';
		while (*strbuff != '\0')
		{
			if (*strbuff++ == '\n')
			{
				t->join = strbuff - i[0] - 1;
				return ((int)i[0] + 1);
			}
			i[0]++;
		}
		buff -= BUFF_SIZE;
	}
	t->join = strbuff - i[0];
	return (-1);
}

		
int		ft_join(t_cont *t, int fd)
{
	char		*strrm;
	int			temp;
	int			temp2;
	int			temp1;
	int			temp3;
	int			lol123;
	size_t		buff;

	buff = BUFF_SIZE;
	temp1 = 0;
	temp2 = t->len;
	if ((temp = ft_findchr(t->str, '\n')) >= 0)
	{
		t->end = temp;
		return (1);
	}
	while (1)
	{
		strrm = t->str - t->tmp;
		if ((temp = ft_buff_join(buff, t, fd, t->join)) > 0)
		{
			t->end = temp2 + temp + temp1 - 1;
			t->str = ft_strjoin(t->str, t->join);
			free(t->join);
			free(strrm);
			t->tmp = 0;
			return (1);
		}
		if (temp == -2)
		{
			t->str = ft_strjoin(t->str, t->join);
			t->len -= t->end;
			free(strrm);
			t->tmp = 0;
			return (-1);
		}
		if (temp == -3)
			return (-1);
		t->str = ft_strjoin(t->str, t->join);
		free(t->join);
		free(strrm);
		t->tmp = 0;
		temp1 += buff;
		buff *= 2;
	}
} 

static char	*ft_str(t_cont *t, int fd)
{
	char	*tmp;
	char	*tmprm;
	int		end;
	
	if ((t->str == NULL))
	{
		t->str = ft_chmalloc_zend(BUFF_SIZE);
		if (!(t->end = (read(fd, t->str, BUFF_SIZE))))
            return (NULL);
		(t->str)[t->end] = '\0';
		t->len = t->end;
	}
	if (ft_join(t, fd) == -1)
	{
		tmp = ft_strdup(t->str);
		free(t->str - t->tmp);
		t->tmp = 0;
		t->str = NULL;
		return (tmp);
	}
	tmp = ft_chmalloc_zend(t->end);
	ft_strncpy(tmp, t->str, t->end++);
	//tmprm = t->str;
	t->str += t->end;
	t->tmp += t->end;
	t->len -= t->end;
	//free(tmprm);
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
