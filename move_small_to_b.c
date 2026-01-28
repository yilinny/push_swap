#include "push_swap.h"

static int count_moves(int pos, snapshot *summary)
{
	//pos starts from 0, 0 being top. Length - 1 will be at the bottom/last 
	int final;
	t_list *current;
	t_list *current_moves;
	int count;
	int pos_b;

	count = pos;
	current = summary->stack_a;
	current_moves = summary->moves;
	while (count > 0)
	{
		current = current ->next;
		count --;
	}
	// number of rotations for a 
	if (pos < ft_lstsize(summary->stack_a)/2)
	{
		final += pos;
		count = final;
		while (count > 0)
		{
			ft_lstadd_back(current_moves, 'ra');
			count --;
		}
	}
	else
	{
		final = ft_lstsize(summary->stack_a) - pos;
		count = final;
		while (count > 0)
		{
			ft_lstadd_back(current_moves, 'rra');
			count --;
		}
	}
	//number of rotations for b 
	pos_b = sort_b(summary->stack_b, current->content);
	if (pos_b < ft_lstsize(stack_b)/2)
		final += pos_b;


};

void move_small_to_b (snapshot *current, int average)
{
	t_list *stack_a = current ->stack_a;
	t_list *stack_b = current->stack_b;
	t_list *moves = current->moves;

	//assumes stack b and moves are initialized 
	//check from front and check from back 
	//calculate moves needed 
}