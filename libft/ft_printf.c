/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:19:12 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/03/08 14:03:04 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_index(char c)
{
	int					index;
	const t_type_table	handle_map[] = {
	{'c', handle_char},
	{'s', handle_str},
	{'p', handle_ptr},
	{'d', handle_int},
	{'i', handle_int},
	{'u', handle_unsigned},
	{'x', handle_hex},
	{'X', handle_hex},
	{'%', handle_char}
	};

	index = 0;
	while (index < 9)
	{
		if (c == handle_map[index].symbol)
			return (index);
		index ++;
	}
	return (-1);
}

static void	print_params(va_list *args, int *printed, char specified)
{
	int					i;
	int					count;
	const t_type_table	handle_map[] = {
	{'c', handle_char},
	{'s', handle_str},
	{'p', handle_ptr},
	{'d', handle_int},
	{'i', handle_int},
	{'u', handle_unsigned},
	{'x', handle_hex},
	{'X', handle_hex},
	{'%', handle_char}
	};

	i = get_index(specified);
	if (i == -1)
		return ;
	count = handle_map[i].func(args, specified);
	(*printed) += count;
	return ;
}

int	ft_printf(const char *str, ...)
{
	int		printed;
	char	*ptr;
	char	specified;
	va_list	args;

	va_start(args, str);
	printed = 0;
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr ++;
			specified = *ptr;
			print_params(&args, &printed, specified);
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
			printed ++;
		}
		ptr ++;
	}
	va_end(args);
	return (printed);
}
