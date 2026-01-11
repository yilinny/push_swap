/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:44:11 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/25 14:23:29 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_in_set(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		start;
	int		end;

	start = 0;
	while (s1[start] && check_in_set(s1[start], set))
		start ++;
	end = ft_strlen(s1) - 1;
	while (end >= start && check_in_set(s1[end], set))
		end --;
	if (start > end)
		return (ft_strdup(""));
	final = ft_substr(s1, (unsigned int)(start), end - start + 1);
	return (final);
}
