#include "librb.h"

void	ft_rotate_left(t_node *t)
{
	t_node *pivot = t->r;

	pivot->p = t->p;
	if (t->p != NULL) {
		if (t->p->l == t)
			t->p->l = pivot;
		else
			t->p->r = pivot;
	}		

	t->r = pivot->l;
	if (pivot->l != NULL)
		pivot->l->p = t;

	t->p = pivot;
	pivot->l = t;
}

void	ft_rotate_right(t_node *t)
{
	t_node *pivot = t->l;

	pivot->p = t->p; 
	if (t->p != NULL) {
		if (t->p->l == t)
			t->p->l = pivot;
		else
			t->p->r = pivot;
	}		

	t->l = pivot->r;
	if (pivot->r != NULL)
		pivot->r->p = t;

	t->p = pivot;
	pivot->r = t;
}
