#include "libft.h"

long int		ft_findchr(const char *str, int s)
{
	long int	i;

	i = 0;
	while (*str != (char)s && *str != '\0')
	{
			++str;
			++i;
	}
	if (*(str) == (char)s)
		return (i);
	return (-1);
}
