/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librb.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:55:12 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 15:52:05 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRB_H
# define LIBRB_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

enum				rb_color
{
	BLACK,
	RED
};

typedef struct		s_node
{
	void				*d;
	enum rb_color		c;
	struct s_node		*l;
	struct s_node		*r;
	struct s_node		*p;
}					t_node;

typedef struct		s_cont
{
	int			fd;
	char		*str;
	char		*join;
	char		*rm;
	size_t		end;
	size_t		tmp;
	size_t		len;
	size_t		i_len;
}					t_cont;

t_node				*ft_create_node(void *data);
t_node				*ft_insert_node(t_node *root, t_node *t, int (*f)
		(void *, void *));
t_node				*ft_grandp_node(t_node *t);
t_node				*ft_uncle_node(t_node *t);
void				ft_rotate_left(t_node *t);
void				ft_rotate_right(t_node *t);
void				ft_insert_case1(t_node *t);
void				ft_insert_case2(t_node *t);
void				ft_insert_case3(t_node *t);
void				ft_insert_case4(t_node *t);
void				ft_insert_case5(t_node *t);
t_node				*ft_find_node_fd(t_node *list, int fd);
t_cont				*ft_create_cont_fd(int fd, char *str);
int					ft_cmp_fd(t_cont a, t_cont b);

#endif
