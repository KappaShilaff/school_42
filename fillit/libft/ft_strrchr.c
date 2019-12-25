/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:47:24 by kdagmer           #+#    #+#             */
/*   Updated: 2019/06/03 19:05:09 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ret = (char *)s;
		s++;
	}
	if (ret)
		return (ret);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
