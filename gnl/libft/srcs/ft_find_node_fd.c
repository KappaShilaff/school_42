/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_node_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:22:14 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 15:23:37 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "librb.h"

t_node	*ft_find_node_fd(t_node *list, int fd)
{
	t_node	*tmp;
	t_cont	*cont;

	if (!list)
		return (NULL);
	tmp = list;
	cont = tmp->d;
	while (cont->fd != fd && tmp)
	{
		if (cont->fd > fd)
			tmp = tmp->r;
		else
			tmp = tmp->l;
		if (tmp)
			cont = tmp->d;
	}
	return (tmp);
}
