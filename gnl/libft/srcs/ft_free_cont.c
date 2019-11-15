/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:22:41 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/15 16:22:44 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "librb.h"

int		ft_free_cont(t_cont *t)
{
	int	fd;

	fd = t->fd;
	ft_bzero(t, sizeof(t_cont));
	t->fd = fd;
	return (0);
}
