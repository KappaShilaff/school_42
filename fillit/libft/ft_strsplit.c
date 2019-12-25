/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:44:43 by kdagmer           #+#    #+#             */
/*   Updated: 2019/06/13 16:22:50 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_findwords(char const *s, int i, char c, char **res)
{
	int l;
	int j;

	l = 0;
	j = 0;
	while (*s == c)
	{
		s++;
		j++;
	}
	while (s[l] && s[l] != c)
		l++;
	if (l > 0)
	{
		if ((res[i] = ft_strnew(l)) == NULL)
		{
			while (--i >= 0)
			{
				ft_strdel(&res[i]);
			}
			return (0);
		}
		ft_strncpy(res[i], s, l);
	}
	return (j + l);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		l;

	if (!s)
		return (NULL);
	j = ft_words_counter(s, c, 0, 0);
	if (!(res = (char**)ft_memalloc((j + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s)
	{
		l = ft_findwords(s, i++, c, res);
		if (l == 0)
		{
			free(res);
			res = NULL;
			return (NULL);
		}
		s += l;
	}
	res[j] = 0;
	return (res);
}
