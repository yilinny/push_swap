/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:47:33 by yi0ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:40:41 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*final;
	unsigned int	index;
	unsigned int	length;

	index = 0;
	if (!s)
		return (NULL);
	length = (unsigned int)ft_strlen(s);
	final = (char *)malloc(length + 1);
	if (final == NULL)
		return (NULL);
	while (index < length)
	{
		final[index] = f(index, s[index]);
		index ++;
	}
	final[length] = '\0';
	return (final);
}
