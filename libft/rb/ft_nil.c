#include "librb.h"

t_node	*ft_nil()
{
	t_node	*nil;

	nil = ft_create_node((void *)"nil");
	nil->c = BLACK;
	return (nil);
}
