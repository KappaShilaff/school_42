#include "libft.h"

void	ft_lstfree(void *content, size_t content_size)
{
	if (content_size)
		content_size = 0;
	if (content)
		free(content);
}
