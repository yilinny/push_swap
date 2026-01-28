#include "push_swap.h"

static int count_moves(int pos, snapshot *summary)
{
	//pos starts from 0, 0 being top. Length - 1 will be at the bottom/last 
	int final;
	t_list *current;
	char rotation_flag;
	int count;
	int pos_b;
	int rot_a;

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
		rot_a = pos;
		rotation_flag = 'u'; // everything goes up 
	}
	else
	{
		rot_a= ft_lstsize(summary->stack_a) - pos;
		rotation_flag = 'd'; // top goes down, everything goes down 

	}
	//number of rotations for b 
	pos_b = sort_b(summary->stack_b, current->content);
	int rot_b;
	if (pos_b < ft_lstsize(summary->stack_b)/2)
    	rot_b = pos_b;   // rb
	else
    	rot_b = ft_lstsize(summary->stack_b) - pos_b; // rrb
	if (rotation_flag == 'u' && pos_b < ft_lstsize(summary->stack_b)/2)
    	final = (rot_a > rot_b) ? rot_a : rot_b; // rr
	else if (rotation_flag == 'd' && pos_b >= ft_lstsize(summary->stack_b)/2)
    	final = (rot_a > rot_b) ? rot_a : rot_b; // rrr
	else
    	final = rot_a + rot_b; // separate rotations

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