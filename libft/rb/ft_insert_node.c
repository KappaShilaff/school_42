#include "librb.h"

static t_node  *ft_root(t_node *t)
{
	t_node  *root;

	root = t;
	while (root->p)
		root = root->p;
	return (root);
}

t_node	*ft_insert_node(t_node *root, t_node *t)
{
	if (root)
	{
		while (root != NULL)
		{
			if (t->d > root->d)
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
		if (t->d > root->d)
			root->r = t;
		else
			root->l = t;
		ft_insert_case1(t);
	}
	return (ft_root(root));
}
