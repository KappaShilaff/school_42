/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:54:02 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/05 16:21:09 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*range;
	int		i;

	i = 0;
	if (min >= max || !(range = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
