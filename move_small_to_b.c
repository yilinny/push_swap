#include "push_swap.h"

static int count_moves(int pos, snapshot *summary)
{
	//pos starts from 0, 0 being top. Length - 1 will be at the bottom/last 
	int final;
	t_list *current;
	char rotation_flag;
	int count;
	int pos_b;

	final = 0;
	count = pos;
	current = summary->stack_a;
	while (count > 0)
	{
		current = current ->next;
		count --;
	}
	// number of rotations for a 
	if (pos < ft_lstsize(summary->stack_a)/2)
	{
		final += pos;
		rotation_flag = 'u'; // everything goes up 
	}
	else
	{
		final += ft_lstsize(summary->stack_a) - pos;
		rotation_flag = 'd'; // top goes down, everything goes down 

	}
	//number of rotations for b 
	pos_b = sort_b(summary->stack_b, current->content);
	if (pos_b < ft_lstsize(summary->stack_b)/2)
	{	
		if (rotation_flag == 'u')
		{
			if (pos_b - pos > 0)
				final += (pos_b - pos);
		}
		else
			final += pos_b;
	}
	else 
	{
		count = ft_lstsize(summary->stack_b) - pos_b;
		if (rotation_flag == 'd')
		{
			if (count - final > 0)
				final += (pos_b - pos);
		}
		else
			final += count;
	}
	return (final);
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