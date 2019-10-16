#include "librb.h"

void	ft_insert_case5(t_node *t)
{
	t_node	*g;

	g = ft_grandp_node(t);
	{
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

	if (g = ft_grandp_node(t))
	{
		if ((t == t->p->r) && (t->p == g->l))
		{
			ft_rotate_left(t->p);
			t = t->l;
		} else if ((t == t->p->l) && (t->p == g->r))
		{
			ft_rotate_right(t->p);
			t = t->r;
		}
	ft_insert_case5(t);
	}
}

void	ft_insert_case3(t_node *t)
{
	t_node	*u;
	t_node	*g;

	u = ft_uncle_node(t);
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
