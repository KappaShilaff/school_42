#include "libft.h"

size_t	ft_findchr(char *str, char s)
{
	size_t	i;

	i = 0;
	while (str[i] != s && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (i);
}
