#include "librb.h"
#include <stdio.h>

t_node	*ft_root(t_node *t)
{
	t_node	*temp;

	temp = t;
	while (temp->p)
	{
		temp = temp->p;
	}
	return (temp);
}

void	btree_apply_prefix(t_node *root)
{
		if (root)
		{
			printf("\n");
			if (root)
				printf("root %i ", (int)root->d); 
			if (root->l)
				printf("left %i ", (int)root->l->d); 
			if (root->r)
				printf("right %i ", (int)root->r->d); 
		btree_apply_prefix(root->r);
		btree_apply_prefix(root->l);
		}
}

int		main(void)
{
	t_node *lol1 = ft_create_node((void *)1);
	t_node *lol2 = ft_create_node((void *)3);
	t_node *lol3 = ft_create_node((void *)12);
	t_node *lol4 = ft_create_node((void *)100);
	t_node *lol5 = ft_create_node((void *)40);
	t_node *lol6 = ft_create_node((void *)35);
	t_node *lol7 = ft_create_node((void *)42);
	t_node *lol8 = ft_create_node((void *)13);
	t_node *lol9 = ft_create_node((void *)19);
	t_node *lol10 = ft_create_node((void *)159);
	t_node *lol11 = ft_create_node((void *)500);
	t_node *lol12 = ft_create_node((void *)600);
	t_node *lol13 = ft_create_node((void *)123);
	t_node *lol14 = ft_create_node((void *)321);
	t_node *lol15 = ft_create_node((void *)567);
	t_node *lol16 = ft_create_node((void *)950);
	t_node *lol17 = ft_create_node((void *)199);
	t_node *lol18 = ft_create_node((void *)76);
	t_node *lol19 = ft_create_node((void *)122);
	t_node *lol20 = ft_create_node((void *)133);
	t_node *lol21 = ft_create_node((void *)101);

	ft_insert_node(ft_root(lol1), lol2);
	ft_insert_node(ft_root(lol2), lol3);
	ft_insert_node(ft_root(lol8), lol1);
	ft_insert_node(ft_root(lol8), lol5);
	ft_insert_node(ft_root(lol8), lol6);
	ft_insert_node(ft_root(lol8), lol7);
	ft_insert_node(ft_root(lol8), lol4);
	ft_insert_node(ft_root(lol8), lol9);
	ft_insert_node(ft_root(lol8), lol10);
	ft_insert_node(ft_root(lol8), lol11);
	ft_insert_node(ft_root(lol8), lol12);
	ft_insert_node(ft_root(lol8), lol13);
	ft_insert_node(ft_root(lol8), lol14);
	ft_insert_node(ft_root(lol8), lol15);
	ft_insert_node(ft_root(lol8), lol16);
	ft_insert_node(ft_root(lol8), lol17);
	ft_insert_node(ft_root(lol8), lol18);
	ft_insert_node(ft_root(lol8), lol19);
	ft_insert_node(ft_root(lol8), lol20);
	ft_insert_node(ft_root(lol1), lol21);

	btree_apply_prefix(ft_root(lol4));
	printf("\n");
	return (0);
}
