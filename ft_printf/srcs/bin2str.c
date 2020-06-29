/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin2str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:14:54 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/29 19:15:33 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*bin2str(char *str)
{
	char	*res;
	char	*buf;
	char	*exp;
	int		i;

	i = 2;
	res = ft_strdup("0.0\0");
	while (str[i] != '\0')
	{
		if (str[i] == '1')
		{
			buf = res;
			exp = ft_chexp("0.5", i - 1);
			res = ft_chsum(res, exp);
			free(exp);
			free(buf);
		}
		i++;
	}
	if (str[0] == '1')
		res[0] = '1';
	return (res);
}
