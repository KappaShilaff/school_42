#include "libft.h"

void	ft_fix_insert_rb(t_rb_node **root, t_rb_node *t)
{
	if (*root == t)
	{
		t->color = RB_BLACK;
		return ;
	}
	while (t->parent->color == RB_RED)
		{
			if (t->parent == t->parent->parent->left)
			{
				if (t->parent->parent->right)
				{
					if (t->parent->parent->right->color == RB_RED)
					{
						t->parent->color = RB_BLACK;
						t->parent->parent->right->color = RB_BLACK;
						t->parent->parent->color = RB_RED;
						t = t->parent->parent;
					}
				}
				else
				{
					if (t == t->parent->right)
					{
						t = t->parent;
						ft_left_rotate_rb(t);
					}
					else
					{
						t->parent->color = RB_BLACK;
						t->parent->parent->color = RB_RED;
						ft_right_rotate_rb(t->parent->parent);
					}
				}
			}
			else
			{
				if (t->parent->left)
				{
					if (t->parent->parent->left->color == RB_RED)
					{
						t->parent->color = RB_BLACK;
						t->parent->parent->left->color = RB_BLACK;
						t->parent->parent->color = RB_RED;
						t = t->parent->parent;
					}
				}
				else
					{
						if (t == t->parent->left)
						{
							t = t->parent;
							ft_right_rotate_rb(t);
						}
						t->parent->color = RB_BLACK;
						t->parent->parent->color = RB_RED;
						ft_left_rotate_rb(t->parent->parent);
					}
			}
		}
		(*root)->color = RB_BLACK;
}

void	ft_insert_rb(t_rb_node **root, t_rb_node *t)
{
	t_rb_node	*p;
	t_rb_node	*q;

	t->color = RB_RED;
	p = *root;
	q = NULL;
	if (!*root || *root)
	{
		*root = t;
		t->parent = NULL;
	}	else
	{
		while (p)
		{
			q = p;
			if (p->data < t->data)
				p = p->right;
			else
				p = p->left;
			if (q->data < t->data)
				q->right = t;
			else
				q->left = t;
		}
	ft_fix_insert_rb(root, t);
	}
}
