#include "librb.h"

static t_node  *ft_root(t_node *t)
{
	t_node  *root;

	root = t;
	while (root->p)
		root = root->p;
	return (root);
}

t_node	*ft_insert_node(t_node *root, t_node *t, int (*f)(void *, void *))
{
	if (root)
	{
		while (root != NULL)
		{
			if ((*f)(t->d, root->d) > 0)
			{
				t->p = root;
				root = root->r;
			}
			else
			{ 
				t->p = root;
				root = root->l;
			}
		}
		root = t->p;
		if ((*f)(t->d, root->d) > 0)
			root->r = t;
		else
			root->l = t;
		ft_insert_case1(t);
	}
	return (ft_root(root));
}
