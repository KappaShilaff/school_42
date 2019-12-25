/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:09:41 by kdagmer           #+#    #+#             */
/*   Updated: 2019/06/13 16:05:42 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstnew;

	if (lst)
	{
		lstnew = f(lst);
		lstnew->next = ft_lstmap(lst->next, f);
		return (lstnew);
	}
	return (NULL);
}
