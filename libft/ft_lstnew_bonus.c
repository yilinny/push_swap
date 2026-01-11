/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:46:03 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:42:29 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*final;

	final = (t_list *)malloc(sizeof(t_list));
	if (!final)
		return (NULL);
	final -> content = content;
	final -> next = NULL;
	return (final);
}
