#include "libft.h"

char	*ft_chmalloc_zend(size_t i)
{
	char	*str;

	str = malloc(i + 1);
	str[i] = '\0';
	return (str);
}
