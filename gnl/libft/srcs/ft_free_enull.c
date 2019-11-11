#include "libft.h"

int		ft_free_enull(char **str)
{
	free(*str);
	*str = NULL;
	return (0);
}
