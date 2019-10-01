/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:07:08 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/19 16:02:09 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strchr(const char *str, int ch)
{
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(str);
	if ((char)ch == '\0')
		return ((char *)&str[len]);
	while (str[i] && i < len)
		if (str[i++] == (char)ch)
			return ((char *)&str[i - 1]);
	return (0);
}
