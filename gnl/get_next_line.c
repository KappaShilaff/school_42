/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:38:44 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/05 20:49:40 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

long int	gnl_n(t_cont *t)
{
	char	*tmp;
	long int	i;
	long int	k;
	long int	buff;
	long int	buff_tmp;

	buff = BUFF_SIZE;
	while (1)
	{
		t->len += t->tmp;
		i = 0;
		t->tmp = 0;
		tmp = t->str;
		t->str = ft_chmalloc_zend(buff);
		t->rm = t->str;
		buff_tmp = buff;
		while (buff_tmp != 0)
		{
			if (!(k = read(t->fd, t->str, BUFF_SIZE)))
			{
				if (buff_tmp == buff)
				{
					t->str = ft_strdup(tmp);
					free(tmp);
					return (-2);
				}
				if (tmp)
				{
					t->str = ft_strjoin(tmp, t->str - i);
					free(tmp);
					free(t->rm);
				}
				else
					t->str = t->str - i;				
				return (-1);
			}
			t->tmp += k;
			t->str[k] = '\0';
			while (*t->str != '\0')
				if (++i && (*(t->str)++ == '\n'))
				{
					if (tmp)
					{
						t->str = ft_strjoin(tmp, t->str - i);
						free(tmp);
						free(t->rm);
					}
					else
						t->str = t->str - i;				
					return (t->len + i - 1);
				}
			buff_tmp -= k;
		}
		if (tmp)
		{
			t->str = ft_strjoin(tmp, t->str - i);
			free(tmp);
			free(t->rm);
		}
		else
			t->str = t->str - i;
		buff *= 2;
	}
	return (0);
}


char	*gnl_str(t_cont *t)
{
	char		*line;
	char		*tmp;
	long int	i;

	if (t->str && (i = ft_findchr(t->str, '\n')) >= 0)
	{
		line = ft_chmalloc_zend(i);
		line = ft_strncpy(line, t->str, i++);
		tmp = t->str;
		t->str = ft_strdup(t->str + i);
		free(tmp);
		t->len -= i;
		return(line);
	}
	if (((i = gnl_n(t)) == -1))
		{
			line = ft_strdup(t->str);
			free(t->str);
			t->str = NULL;
			return (line);
		}
	if (i == -2)
	{
		if (t->len != 0)
		{
			line = ft_chmalloc_zend(t->len);
			line = ft_strncpy(line, t->str, t->len);
			t->str = NULL;
			return (line);
		}
		return (NULL);
	}
	line = ft_chmalloc_zend(i);
	line = ft_strncpy(line, t->str, i++);
	tmp = t->str;
	t->str = ft_strdup(t->str + i);
	t->len = t->len - i;
	free(tmp);
	return (line);
}


int				get_next_line(const int fd, char **line)
{
	static t_node	*head;
	t_node			*curr;
	int				i;

	i = 0;
	if (read(fd, 0, 0) == -1)
		return (-1);
	if (!(curr = ft_find_node_fd(head, fd)))
	{
		curr = ft_create_node(ft_create_cont_fd(fd, NULL));
		head = ft_insert_node(head, curr, (void *)ft_cmp_fd);
		i = 1;
	}
	if (i == 0 && (((t_cont *)(curr->d))->str  == NULL))
		return (0);
	if ((*line = gnl_str((t_cont *)(curr->d))) != NULL)
		return (1);
	return (0);
}
