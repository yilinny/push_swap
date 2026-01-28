#include "stacks.h"
//initialize stack a, add inputted array into linked list format 

snapshot *init_all(int *input, int length)
{
	// convert to rank is called first, so input is a list of int
	int i;
	t_list *stack_a;
	snapshot *all;
	
	all = malloc(sizeof(snapshot));
	stack_a = ft_lstnew_bonus(input[0]);
	i = 1;
	while (i < length)
	{
		ft_lstadd_back(&stack_a, input[i]);
		i ++;
	}
	all->stack_a = stack_a;
	all-> stack_b = NULL;
	all->moves = NULL;
	return (all);
}
//rotate list
void make_moves (snapshot *current, char *move)
{
	if (move == "sa")
		swap_stack(current ->stack_a);
	else if (move == "sb")
		swap_stack(current ->stack_b);
	
	add_moves(current->moves, move);
}


void swap_stack(t_list stack)
{

}
//condense list eg. if rra rra rrb --> rrr rra
