/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:36:53 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:30:02 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*final;
	size_t	length;

	length = ft_strlen(s);
	final = (char *)malloc((length + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	ft_strlcpy(final, s, length + 1);
	return (final);
}
