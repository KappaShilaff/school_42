#include "libft.h"

char	*ft_memstrncpy(char *new, const char *str, size_t i)
{
	new = ft_chmalloc_zend(i);
	new = ft_strncpy(new, str, i);
	return (new);
}
