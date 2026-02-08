#include "push_swap.h"

void swap_stack (t_list **stack, t_list **none)
{
	t_list	*first;
	t_list	*second;
	(void )none;
	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	second = (*stack) -> next;
	first -> next = second -> next;
	second -> next = first;
	*stack = second;
}

void reverse_rotate_stack (t_list **stack, t_list **none)
{
	// bottom comes to top, last becomes first 
	t_list *last;
	t_list *second_last;
	(void)none;

	if (!stack || !*stack || !((*stack)-> next))
		return;
	second_last = *stack;
	while (second_last -> next -> next != NULL)
		second_last = second_last -> next;
	
	last = second_last -> next;
	second_last -> next = NULL;
	last -> next = *stack;
	*stack = last;
}

void rotate_stack (t_list **stack, t_list **none)
{
	// first element becomes the last one 
	t_list *last;
	t_list *second;
	(void)none;
	if (!stack || !*stack || !(*stack)->next)
		return;
	last = ft_lstlast(*stack);
	second = (*stack)-> next;
	last -> next = *stack;
	(*stack) -> next = NULL;
	*stack = second;
}

void push_stack (t_list **dest, t_list **src)
{
	t_list *move;
	if (!src || !*src)
		return;
	move = *src;
	*src = move -> next;
	ft_lstadd_front(dest, move); // accounts for empty list 
}

