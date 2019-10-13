#include "librb.h"

t_node	*ft_grandp_node(t_node *t)
{
	if ((t != NULL) && (t->p != NULL))
		return (t->p->p);
	else
		return (NULL);
}
