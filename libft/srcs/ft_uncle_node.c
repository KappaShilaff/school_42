#include "librb.h"

t_node	*ft_uncle_node(t_node *t)
{
	t_node	*g;

	g = ft_grandp_node(t);
	if (g == NULL)
		return (NULL);
	if (t->p == g->l)
		return (g->r);
	else
		return (g->l);
}
