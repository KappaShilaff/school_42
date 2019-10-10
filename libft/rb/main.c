#include "librb.h"
#include <stdio.h>

static t_node	*ft_root(t_node *t)
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
	t_node *lol1 = ft_create_node((void *)13);
	t_node *lol2 = ft_create_node((void *)22);
	t_node *lol3 = ft_create_node((void *)138);
	t_node *lol4 = ft_create_node((void *)1);
	t_node *lol5 = ft_create_node((void *)1000);
	t_node *lol6 = ft_create_node((void *)567);
	t_node *lol7 = ft_create_node((void *)9);
	t_node *lol8 = ft_create_node((void *)9999);
	t_node *lol9 = ft_create_node((void *)32);
	t_node *lol10 = ft_create_node((void *)999);
	t_node *lol11 = ft_create_node((void *)555);
	t_node *lol12 = ft_create_node((void *)44);
	t_node *lol13 = ft_create_node((void *)3);
	t_node *lol14 = ft_create_node((void *)321);
	t_node *lol15 = ft_create_node((void *)123);
	t_node *lol16 = ft_create_node((void *)950);
	t_node *lol17 = ft_create_node((void *)199);
	t_node *lol18 = ft_create_node((void *)76);
	t_node *lol19 = ft_create_node((void *)122);
	t_node *lol20 = ft_create_node((void *)133);
	t_node *lol21 = ft_create_node((void *)101);
	t_node *lol0 = ft_create_node((void *)1);
	

	lol0 = ft_insert_node(lol3, lol2);
	lol0 = ft_insert_node(lol0, lol1);
	lol0 = ft_insert_node(lol0, lol4);
	lol0 = ft_insert_node(lol0, lol5);
	lol0 = ft_insert_node(lol0, lol6);
	lol0 = ft_insert_node(lol0, lol7);
	lol0 = ft_insert_node(lol0, lol8);
	lol0 = ft_insert_node(lol0, lol9);
	lol0 = ft_insert_node(lol0, lol10);
	lol0 = ft_insert_node(lol0, lol11);
	lol0 = ft_insert_node(lol0, lol12);
	lol0 = ft_insert_node(lol0, lol13);
	lol0 = ft_insert_node(lol0, lol14);
	lol0 = ft_insert_node(lol0, lol15);
	lol0 = ft_insert_node(lol0, lol16);
	lol0 = ft_insert_node(lol0, lol17);
	lol0 = ft_insert_node(lol0, lol18);
	lol0 = ft_insert_node(lol0, lol19);
	lol0 = ft_insert_node(lol0, lol20);
	lol0 = ft_insert_node(lol0, lol21);

	btree_apply_prefix(lol0);
	printf("\n");
	return (0);
}
