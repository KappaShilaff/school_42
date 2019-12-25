/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:37:04 by kdagmer           #+#    #+#             */
/*   Updated: 2019/05/20 19:59:03 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		if (d == s)
			return (NULL);
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
