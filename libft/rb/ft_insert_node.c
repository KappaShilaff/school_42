#include "librb.h"
#include <stdio.h>

static t_node  *ft_root(t_node *t)
{
	t_node  *temp;

	temp = t;
	while (temp->p)
	{
		temp = temp->p;
	}
	printf("root is %i\n", (int)temp->d);
	return (temp);
}

void	ft_insert_node(t_node *root, t_node *t)
{
	t_node	*temp;

	if (!root)
		return ;
	temp = root;
	while (temp != NULL)
	{
		if (t->d > temp->d)
		{
			t->p = temp;
			temp = temp->r;
		}
		else
		{ 
			t->p = temp;
			temp = temp->l;
		}
	}
	temp = t->p;
	if (t->d > temp->d)
		temp->r = t;
	else
		temp->l = t;
	ft_insert_case1(root);
}
