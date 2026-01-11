/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:06:36 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:46:32 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*final;

	final = lst;
	while (final && final-> next != NULL)
	{
		final = final-> next;
	}
	return (final);
}
