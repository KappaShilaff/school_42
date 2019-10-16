#include "libft.h"
#include <stdio.h>

t_rb_node           *ft_create_node_rb(void *data);
void                ft_insert_rb(t_rb_node **root, t_rb_node *t);

void	btree_apply_prefix(t_rb_node *root)
{
	if (root->left)
	{
		printf("%d", root->data);
		btree_apply_prefix(root->left);
	}
	if (root->right)
	{
		printf("%d", root->data);
		btree_apply_prefix(root->right);
	}
}

int		main(void)
{
	t_rb_node *lol1 = ft_create_node_rb((void *)1);
	t_rb_node *lol2 = ft_create_node_rb((void *)3);
	t_rb_node *lol3 = ft_create_node_rb((void *)12);
	t_rb_node *lol4 = ft_create_node_rb((void *)100);
	t_rb_node *lol5 = ft_create_node_rb((void *)40);
	t_rb_node *lol6 = ft_create_node_rb((void *)35);
	t_rb_node *lol7 = ft_create_node_rb((void *)42);
	t_rb_node *lol8 = ft_create_node_rb((void *)13);
	t_rb_node *lol9 = ft_create_node_rb((void *)12);
	t_rb_node *lol10 = ft_create_node_rb((void *)159);
	t_rb_node *lol11 = ft_create_node_rb((void *)500);
	t_rb_node *lol12 = ft_create_node_rb((void *)600);
	t_rb_node *lol13 = ft_create_node_rb((void *)123);
	t_rb_node *lol14 = ft_create_node_rb((void *)321);
	t_rb_node *lol15 = ft_create_node_rb((void *)567);
	t_rb_node *lol16 = ft_create_node_rb((void *)950);
	t_rb_node *lol17 = ft_create_node_rb((void *)199);
	t_rb_node *lol18 = ft_create_node_rb((void *)111);
	t_rb_node *lol19 = ft_create_node_rb((void *)122);
	t_rb_node *lol20 = ft_create_node_rb((void *)133);
	t_rb_node *lol21 = ft_create_node_rb((void *)0);

	ft_insert_rb(NULL, lol1);
	ft_insert_rb(&lol1, lol2);
	ft_insert_rb(&lol1, lol3);
	ft_insert_rb(&lol1, lol4);
	ft_insert_rb(&lol1, lol5);
	ft_insert_rb(&lol1, lol6);
	ft_insert_rb(&lol1, lol7);
	ft_insert_rb(&lol1, lol8);
	ft_insert_rb(&lol1, lol9);
	ft_insert_rb(&lol1, lol10);
	ft_insert_rb(&lol1, lol11);
	ft_insert_rb(&lol1, lol12);
	ft_insert_rb(&lol1, lol13);
	ft_insert_rb(&lol1, lol14);
	ft_insert_rb(&lol1, lol15);
	ft_insert_rb(&lol1, lol16);
	ft_insert_rb(&lol1, lol17);
	ft_insert_rb(&lol1, lol18);
	ft_insert_rb(&lol1, lol19);
	ft_insert_rb(&lol1, lol20);
	ft_insert_rb(&lol1, lol21);
	
	btree_apply_prefix(lol1);
	return (0);
}
