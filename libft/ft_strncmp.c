/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:18:15 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:31:48 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	a;
	unsigned char	b;

	index = 0;
	while (index < n)
	{
		a = s1[index];
		b = s2[index];
		if (a != b)
			return (a - b);
		if (a == '\0')
			return (0);
		index++;
	}
	return (0);
}
