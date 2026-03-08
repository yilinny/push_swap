/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:43:18 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/03/08 14:05:01 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_ptr(uintptr_t ptr, int *count)
{
	char		c;
	const char	hex[16] = "0123456789abcdef";

	if (ptr >= 16)
		print_ptr(ptr / 16, count);
	c = hex[ptr % 16];
	write (1, &c, 1);
	(*count)++;
}

int	handle_ptr(va_list *args, char symbol)
{
	int			count;
	uintptr_t	ptr;

	if (!symbol)
		return (0);
	count = 0;
	ptr = (uintptr_t)(va_arg(*args, void *));
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	count += 2;
	print_ptr(ptr, &count);
	return (count);
}

char	*hex_string(unsigned int hex_input)
{
	char			*str;
	unsigned int	ctr;
	int				length;
	const char		hex[16] = "0123456789abcdef";

	if (hex_input == 0)
		return (ft_strdup("0"));
	ctr = hex_input;
	length = 0;
	while (ctr > 0)
	{
		length ++;
		ctr = ctr / 16;
	}
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	str[length] = '\0';
	while (length > 0)
	{
		str[length - 1] = hex[hex_input % 16];
		hex_input = hex_input / 16;
		length --;
	}
	return (str);
}

int	handle_hex(va_list *args, char symbol)
{
	unsigned int	hex_input;
	char			*str;
	int				length;
	int				i;

	hex_input = va_arg(*args, unsigned int);
	str = hex_string(hex_input);
	if (!str)
		return (0);
	length = ft_strlen(str);
	i = 0;
	if (symbol == 'X')
	{
		while (i < length)
		{
			str[i] = ft_toupper(str[i]);
			i ++;
		}
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}
