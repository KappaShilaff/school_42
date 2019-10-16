#include "libft.h"

void	*ft_left_rotate_rb(t_rb_node *t)
{
	t_rb_node	*temp;

	temp = t->right;
	t->right = temp->left;
	temp->left = t;
	return (temp);
}
