/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 08:48:31 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:31:01 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	index;

	index = 0;
	count = ft_strlen(src);
	if (size == 0)
		return (count);
	while (index < count && index < size - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (count);
}
