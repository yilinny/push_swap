#include "push_swap.h"

int sort_b(t_list *stack_b, int value)
{
    t_list *curr;
    int curr_val;
    int next_val;
    int pos;

	pos = 0;
    if (!stack_b || !stack_b->next)
        return 0;

    curr = stack_b;
    while (curr->next)
    {
        curr_val = *(int *)curr->content;
        next_val = *(int *)curr->next->content;
        // Case 1: normal descending insertion
        if (curr_val > value && value > next_val)
            return pos + 1;
        // Case 2: rotation break (max/min)
        if (curr_val < next_val && (value > next_val || value < curr_val))
			return pos + 1;
        curr = curr->next;
        pos++;
    }
    return 0;
}


static int count_moves(int pos, t_snapshot *summary)
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
	pos_b = sort_b(summary-> stack_b, *(int *)(current->content));
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

static void move_to_b (int pos, t_snapshot *summary)
{
	int b_pos;
	pos_to_top(pos, 'a', summary);
	b_pos = sort_b(summary->stack_b, *(int *)(summary->stack_a->content));
	pos_to_top(b_pos, 'b', summary);
	alter_summary(summary, "pb");
}

void move_small_to_b(t_snapshot *summary, int pivot)
{
    if (!summary || !summary->stack_a)
        return;

    t_list *current = summary->stack_a;
    int best_top = -1;
    int best_bottom = -1;
	int pointer = 0;

	// walk through list, if number < pivot point, update either top or bottom index 
	while (current)
	{
		if (*(int *)(current ->content) < pivot)
		{
			if (best_top == -1)
				best_top = pointer;
			best_bottom = pointer;
		}
		current = current -> next;
		pointer ++;
	}
    if (count_moves(best_top, summary) <= count_moves(best_bottom, summary))
		move_to_b(best_top, summary);
    else
        move_to_b(best_bottom, summary);
}