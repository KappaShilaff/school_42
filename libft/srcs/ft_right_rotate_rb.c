#include "libft.h"

void	*ft_right_rotate_rb(t_rb_node *t)
{
	t_rb_node	*temp;

	temp = t->left;
	t->left = temp->right;
	temp->right = t;
	return (temp);
}
