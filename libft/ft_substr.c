/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:41:11 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:32:53 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;
	char	*copy;
	int		s_len;

	copy = (char *)s;
	if (ft_strlen(copy) <= start)
		return (ft_strdup(""));
	s_len = ft_strlen(s);
	if (s_len - start < len)
		len = s_len - start;
	final = (char *)malloc(len + 1);
	if (final == NULL)
		return (NULL);
	ft_strlcpy(final, copy + start, len + 1);
	return (final);
}
