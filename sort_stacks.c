#include "push_swap.h"
int check_sorted(int length, t_list **stack, int smallest)
{
	t_list *node;
	int i;
	int pos;

	node = *stack;
	i = 0;
	pos= 1;
	while (node -> next && node ->content != smallest)
	{
		node = node ->next;
		pos ++;
	}
	// this basically moves node until node->content is smallest, and pos will give the position of the smallest value 
	while (i < length)
	{
		if (node->content != smallest + i)
			return (0);
		if (node ->next == NULL)
			node = *stack;
		else 
			node = node->next;
		i ++;
	} //loops through node, expecting each to increment by 1. Returns 0 the moment that is false 
	return (pos); // position of current smallest is returned. 
}
static int calculate_average(int length, int smallest)
{
	if (length % 2 != 0)
		length += 1;
	return((length - smallest)/2);
}

int sort_stacks (snapshot *current, int length, int smallest)
{
	int average;
	t_list *stack_a;
	int pos;


	stack_a = current->stack_a;
	pos = check_sorted(length, &stack_a, smallest);
	if (pos != 0)
		return(pos);
	average = calculate_average(length, smallest);
	move_small_to_b(current, average);
	smallest = average;// index starts from 0 so the average rank is still present in stack A
	length = length/2;
	sort_stacks(current, length, smallest);
}
