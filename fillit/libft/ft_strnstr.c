/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 19:02:44 by kdagmer           #+#    #+#             */
/*   Updated: 2019/05/19 22:57:20 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t i;
	size_t j;

	if (!*need)
		return ((char*)hay);
	i = 0;
	while (*(hay + i))
	{
		j = 0;
		while (*(hay + i + j) && *(hay + i + j) == *(need + j) && (i + j) < len)
		{
			if (!(*(need + j + 1)))
				return ((char*)hay + i);
			j++;
		}
		i++;
	}
	return (0);
}
