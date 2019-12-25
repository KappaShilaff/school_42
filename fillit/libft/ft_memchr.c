/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:22:15 by kdagmer           #+#    #+#             */
/*   Updated: 2019/06/04 18:46:43 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char *)s;
	while (n--)
	{
		if (*(buf++) == (unsigned char)c)
			return (buf - 1);
	}
	return (NULL);
}
