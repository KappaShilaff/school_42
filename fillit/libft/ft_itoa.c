/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:21:57 by kdagmer           #+#    #+#             */
/*   Updated: 2019/06/04 22:11:58 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		nbr;
	int		sign;
	int		len;
	char	*str;

	sign = (n < 0 ? 1 : 0);
	len = (n == 0 ? 1 : 0);
	nbr = n;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	nbr = (n > 0 ? -n : n);
	if (!(str = (char*)malloc(sizeof(char) * len + sign + 1)))
		return (NULL);
	str[len + sign] = '\0';
	while (len > 0)
	{
		str[--len + sign] = -(nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
