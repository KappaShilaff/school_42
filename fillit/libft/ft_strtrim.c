/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdagmer <kdagmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:24:26 by kdagmer           #+#    #+#             */
/*   Updated: 2019/06/03 18:43:05 by kdagmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start]
			&& (s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
		start++;
	end = ft_strlen(s);
	while (start < end
			&& (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t'))
		end--;
	len = end - start;
	return (ft_strsub(s, start, len));
}
