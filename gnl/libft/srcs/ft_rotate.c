/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:09:04 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 15:11:56 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librb.h"

void	ft_rotate_left(t_node *t)
{
	t_node *pivot;

	if (!(t->r))
		return ;
	pivot = t->r;
	pivot->p = t->p;
	if (t->p != NULL)
	{
		if (t->p->l == t)
			t->p->l = pivot;
		else
			t->p->r = pivot;
	}
	t->r = pivot->l;
	if (pivot->l != NULL)
		pivot->l->p = t;
	t->p = pivot;
	pivot->l = t;
}

void	ft_rotate_right(t_node *t)
{
	t_node	*pivot;

	*pivot = t->l;
	if (!(t->l))
		return ;
	pivot = t->l;
	pivot->p = t->p;
	if (t->p != NULL)
	{
		if (t->p->l == t)
			t->p->l = pivot;
		else
			t->p->r = pivot;
	}
	t->l = pivot->r;
	if (pivot->r != NULL)
		pivot->r->p = t;
	t->p = pivot;
	pivot->r = t;
}
