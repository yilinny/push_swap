/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:17:30 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/01/28 14:15:33 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct snapshot
{
	struct t_list *stack_a;
	struct t_list *stack_b;
	struct t_list *moves;
} snapshot;

void	swap_stack(t_list **stack);
void	reverse_rotate_stack(t_list **stack);
void	rotate_stack(t_list **stack);
void	push_stack(t_list **src, t_list **dest);
void	convert_to_rank(int *input, int length);
void	move_small_to_b(snapshot *current, int average);

#endif