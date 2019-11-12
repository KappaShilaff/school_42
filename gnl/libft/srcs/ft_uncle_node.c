/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uncle_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:07:58 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 15:08:01 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librb.h"

t_node	*ft_uncle_node(t_node *t)
{
	t_node	*g;

	g = ft_grandp_node(t);
	if (g == NULL)
		return (NULL);
	if (t->p == g->l)
		return (g->r);
	else
		return (g->l);
}
