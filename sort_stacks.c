#include "push_swap.h"
int check_sorted(int length, t_list **stack, int smallest)
{
	t_list *node;
	int i;
	int pos;

	node = *stack;
	i = 0;
	pos= 0;
	while (node -> next && *(int *)(node->content) != smallest)
	{
		node = node ->next;
		pos ++;
	}
	if (!node)
		return -1;
	// this basically moves node until node->content is smallest, and pos will give the position of the smallest value 
	while (i < length)
	{
		if (*(int *)(node->content) != smallest + i)
			return (-1);
		if (node ->next == NULL)
			node = *stack;
		else 
			node = node->next;
		i ++;
	} //loops through node, expecting each to increment by 1. Returns 0 the moment that is false 
	return (pos); // position of current smallest is returned, 0 is top 
}
static int calculate_move(int length, int smallest)
{
	//anything less THAN moves, equal to does NOT move. 
	if (length < 4)
		return(smallest + 1); 
	if (length == 4)
		return (smallest + 2);
	if (length % 2 != 0)
		length += 1;
	return(smallest + (length/2));
	
}

static int check_moved (t_list *stack, int pivot)
{
	t_list *current;
	if (!stack)
		return (1);
	current = stack;
	while (current)
	{
		if (*(int *)(current -> content) <  pivot)
			return(0);
		current = current -> next;
	}
	return(1);
}

int sort_stacks (t_snapshot *current, int length, int smallest)
{
	int move_point;
	t_list *stack_a;
	int pos;

	stack_a = current->stack_a;
	pos = check_sorted(length, &stack_a, smallest);
	if (pos != -1)
		return(pos);
	move_point = calculate_move(length, smallest);
	while (check_moved(current->stack_a, move_point) == 0)
		move_small_to_b(current, move_point);
	smallest = move_point;// index starts from 0 so the average rank is still present in stack A
	length = length/2;
	return(sort_stacks(current, length, smallest));
}
