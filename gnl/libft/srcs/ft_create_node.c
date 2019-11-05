#include "librb.h"

t_node	*ft_create_node(void *data)
{
	t_node	*t;

	if (!(t = malloc(sizeof(t_node))))
		return (NULL);
	t->d = data;
	t->c = RED;
	t->l = NULL;
	t->r = NULL;
	t->p = NULL;
	return (t);
}
