/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:24:33 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/03/08 14:04:59 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_char(va_list *args, char symbol)
{
	char	c;

	if (symbol == '%')
		ft_putchar_fd('%', 1);
	else
	{
		c = va_arg(*args, int);
		ft_putchar_fd(c, 1);
	}
	return (1);
}

int	handle_str(va_list *args, char symbol)
{
	char	*c;

	if (!symbol)
		return (0);
	c = va_arg(*args, char *);
	if (!c)
		c = "(null)";
	ft_putstr_fd(c, 1);
	return (ft_strlen(c));
}

int	handle_int(va_list *args, char symbol)
{
	int		num;
	char	*str;
	int		length;

	if (!symbol)
		return (0);
	num = va_arg(*args, int);
	str = ft_itoa(num);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free(str);
	return (length);
}

int	handle_unsigned(va_list *args, char symbol)
{
	unsigned int	num;
	char			*str;
	int				length;

	if (!symbol)
		return (0);
	num = va_arg(*args, unsigned int);
	str = ft_utoa(num);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free (str);
	return (length);
}
