#include "librb.h"
#include <stdio.h>

void	ft_insert_case5(t_node *t)
{
	t_node	*g;

	if (t && t->p && t->p->p);
	{
		g = ft_grandp_node(t);
		t->p->c = BLACK;
		g->c = RED;
		if ((t == t->p->l) && (t->p == g->l))
		{
			ft_rotate_right(g);
		} else {
			ft_rotate_left(g);
		}
	}
}

void	ft_insert_case4(t_node *t)
{
	t_node	*g;
	t_node	*saved_p;
	t_node	*saved_l;
	t_node	*saved_r;

	if(g = ft_grandp_node(t))
	{
		if ((t == t->p->r) && (t->p == g->l))
		{
			saved_p = g->l;
			saved_l = t->l;
			g->l = t;
			saved_p->r = saved_l;
			t = t->l;
		} else if ((t == t->p->l) && (t->p == g->r))
		{
			saved_p = g->r;
			saved_r = t->r;
			g->r = t;
			t->r = saved_p;
			saved_p->l = saved_r;
			t = t->r;
		}
	ft_insert_case5(t);
	}
}

void	ft_insert_case3(t_node *t)
{
	t_node	*u;
	t_node	*g;

		if ((u != NULL) && (u->c == RED))
		{
			t->p->c = BLACK;
			u->c = BLACK;
			g = ft_grandp_node(t);
			g->c = RED;
			ft_insert_case1(g);
		} else {
		ft_insert_case4(t);
		}
}

void	ft_insert_case2(t_node *t)
{
	if (t->p->c == BLACK)
		return ;
	else
		ft_insert_case3(t);
}

void	ft_insert_case1(t_node *t)
{
	if (t->p == NULL)
		t->c = BLACK;
	else
		ft_insert_case2(t);
}
