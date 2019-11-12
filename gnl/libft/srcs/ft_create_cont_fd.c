/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cont_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:24:27 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 15:25:17 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "librb.h"

t_cont	*ft_create_cont_fd(int fd, char *str)
{
	t_cont	*t;

	if (!(t = malloc(sizeof(t_cont))))
		return (NULL);
	t->fd = fd;
	t->str = str;
	t->end = 0;
	t->tmp = 0;
	t->len = 0;
	return (t);
}
