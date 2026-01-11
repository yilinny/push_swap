/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:27:04 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:27:28 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*final;

	index = 0;
	final = (unsigned char *)s;
	while (index < n)
	{
		if (final[index] == (unsigned char)c)
			return ((void *)(final + index));
		index++;
	}
	return (NULL);
}
