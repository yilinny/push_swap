/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:37:45 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/20 14:00:18 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	digits(int n)
{
	int	digits;

	if (n < 0)
		n *= -1;
	digits = 0;
	while (n > 0)
	{
		digits += 1;
		n = n / 10;
	}
	return (digits);
}

static char	*deal_with_sign(int *sign, int n, int length)
{
	char	*final;

	if (n < 0)
	{
		final = (char *)malloc(length + 2);
		*sign = 1;
		if (final == NULL)
			return (NULL);
		final[0] = '-';
	}
	else
		final = (char *)malloc(length + 1);
	if (final == NULL)
		return (NULL);
	return (final);
}

char	*ft_itoa(int n)
{
	char	*final;
	int		length;
	int		ctr;
	int		sign;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ctr = 0;
	sign = 0;
	length = digits(n);
	final = deal_with_sign(&sign, n, length);
	if (sign == 1)
		n = -n;
	ctr = length + sign - 1;
	while (ctr >= sign)
	{
		final[ctr] = n % 10 + '0';
		n /= 10;
		ctr --;
	}
	final[length + sign] = '\0';
	return (final);
}
