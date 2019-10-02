#include "libft.h"

t_rb_node	*ft_create_node_rb(void *data)
{
	t_rb_node	*t;

	if (!(t = malloc(sizeof(t))))
		return (NULL);
	t->data = data;
	t->right = NULL;
	t->left = NULL;
	t->parent = NULL;
	return (t);
}
