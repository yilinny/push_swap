/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:32:47 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:31:52 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	char	*final;
	size_t	index;
	size_t	s_index;

	final = (char *)big;
	index = 0;
	if (small[0] == '\0')
		return (final);
	while (big[index] && index < len)
	{
		s_index = 0;
		while (big[index + s_index] == small[s_index] && index + s_index < len)
		{
			s_index ++;
			if (small[s_index] == '\0')
				return (final + index);
		}
		index ++;
	}
	return (NULL);
}
