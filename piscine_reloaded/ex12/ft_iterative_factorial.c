/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:37:24 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/03 18:45:07 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		i;
	int		result;

	if (nb < 0 || nb > 12)
		return (0);
	i = 1;
	result = 1;
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}
