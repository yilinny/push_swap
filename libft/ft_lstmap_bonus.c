/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:57:38 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/12/01 10:15:53 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*next;
	t_list	*head;
	void	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst->content);
		next = ft_lstnew(tmp);
		if (!next)
		{
			del(tmp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, next);
		lst = lst->next;
	}
	return (head);
}
