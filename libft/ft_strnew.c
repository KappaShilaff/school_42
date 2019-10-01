/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:52:46 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/20 15:55:42 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(++size))
		return (0);
	if (!(str = ft_memalloc(size)))
		return (NULL);
	str = ft_memset(str, '\0', size);
	return (str);
}
