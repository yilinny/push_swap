/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:35:08 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/01/11 10:54:33 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t n, size_t esize)
{
	unsigned char	*final;

	if (n == 0 || esize == 0)
		return (malloc(0));
	if (n > SIZE_MAX / esize)
		return (NULL);
	final = malloc(n * esize);
	if (final == NULL)
		return (final);
	ft_memset(final, 0, n * esize);
	return (final);
}
