/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:24:21 by kdagmer           #+#    #+#             */
/*   Updated: 2019/11/24 16:30:48 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(int n)
{
	if (n == 1)
		ft_putstr_fd(ERR1, 1);
	else if (n == 2)
		ft_putstr_fd(ERR2, 1);
	else if (n == 3)
		ft_putstr_fd(ERR3, 1); // remove
	exit(1);
}
