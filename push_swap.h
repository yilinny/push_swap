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
# include "libft\libft.h"
# include <stdio.h>

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;

typedef struct {
	char	*move;
	void (*func)(t_list **, t_list **);
} stack_table;

typedef struct snapshot
{
	t_list *stack_a;
	t_list *stack_b;
	t_list *moves;
} t_snapshot;

void	swap_stack(t_list **stack, t_list **none);
void	reverse_rotate_stack(t_list **stack, t_list **none);
void	rotate_stack(t_list **stack, t_list **none);
void	push_stack(t_list **dest, t_list **src);
void	convert_to_rank(int *input, int length);
t_snapshot *init_summary (int *input, int length);
void	move_small_to_b(t_snapshot *current, int average);
int 	sort_stacks (t_snapshot *current, int length, int smallest);
void alter_summary(t_snapshot *summary, char *move);
int	check_sorted(int length, t_list **stack, int smallest);
void print_snapshot(t_snapshot *summary);
void print_linked_list(t_list *list);
#endif