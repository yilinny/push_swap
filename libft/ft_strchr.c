/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:10:22 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:29:22 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*final;

	index = 0;
	final = (char *)s;
	if (c == 0)
		return (final + ft_strlen(s));
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return (final + index);
		index++;
	}
	return (NULL);
}
