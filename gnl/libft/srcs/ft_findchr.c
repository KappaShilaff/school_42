/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:21:38 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 15:21:55 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
