/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:31:46 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:27:30 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*s_one;
	unsigned char	*s_two;

	index = 0;
	s_one = (unsigned char *)s1;
	s_two = (unsigned char *)s2;
	while (index < n)
	{
		if (s_one[index] != s_two[index])
			return (s_one[index] - s_two[index]);
		index++;
	}
	return (0);
}
