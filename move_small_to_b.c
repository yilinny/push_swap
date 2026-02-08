#include "push_swap.h"

int sort_b(t_list *stack_b, int value)
{
    t_list *curr;
    int curr_val;
    int next_val;
    int pos = 0;

    if (!stack_b || !stack_b->next)
        return 0;

    curr = stack_b;
    while (curr->next)
    {
        curr_val = *(int *)curr->content;
        next_val = *(int *)curr->next->content;
        // Case 1: normal descending insertion
        if (curr_val >= value && value >= next_val)
            return pos + 1;
        // Case 2: rotation break (max/min)
        if (curr_val < next_val &&
            (value > curr_val || value < next_val))
            return pos + 1;
        curr = curr->next;
        pos++;
    }
    // Last → first (cyclic check)
    curr_val = *(int *)curr->content;
    next_val = *(int *)stack_b->content;

    if (curr_val >= value && value >= next_val)
        return 0;
    if (curr_val < next_val &&
        (value > curr_val || value < next_val))
        return 0;
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

static void pos_to_top (int pos, char stack, t_snapshot *summary)
{
	int length;
	if (stack == 'a')
		length = ft_lstsize(summary->stack_a);
	else
		length = ft_lstsize(summary->stack_b);
	
	if (pos == 0)
		return;
	if (pos < length/2 && stack == 'a')
	{
		while (pos > 0)
		{
			alter_summary(summary, "ra");
			pos --;
		}
	}
	else if (pos < length /2 && stack == 'b')
	{
		while (pos > 0)
		{
			alter_summary(summary, "rb");
			pos --;
		}
	}
	else if (stack == 'a')
	{
		while (pos < length)
		{
			alter_summary(summary, "rra");
			pos ++;
		}
	}
	else
	{
		while (pos < length)
		{
			alter_summary(summary, "rrb");
			pos ++;
		}
	}
}

static void move_to_b (int pos, t_snapshot *summary)
{
	int b_pos;
	pos_to_top(pos, 'a', summary);
	b_pos = sort_b(summary->stack_b, *(int *)(summary->stack_a->content));
	printf("\nB_pos is %d", b_pos);
	pos_to_top(b_pos, 'b', summary);
	alter_summary(summary, "pb");
	//condense_moves(summary);
}

void move_small_to_b(t_snapshot *summary, int average)
{
    if (!summary || !summary->stack_a)
        return;

    t_list *current = summary->stack_a;
    int size = ft_lstsize(summary->stack_a);
    int from_top = 0;
    int from_bottom = 0;

    // Count distance from top
    while (current && *(int *)(current->content) > average)
    {
        current = current->next;
        from_top++;
    }

    // Count distance from bottom (without modifying stack)
    current = summary->stack_a;
    from_bottom = 0;
    t_list *last = ft_lstlast(summary->stack_a);
    while (last && *(int *)(last->content) > average)
    {
        last = summary->stack_a;
        for (int i = 0; i < size - from_bottom - 2; i++)
            last = last->next;
        from_bottom++;
    }

    // Decide which requires fewer moves
    if (count_moves(from_top, summary) <= count_moves(from_bottom, summary))
        move_to_b(from_top, summary);
    else
        move_to_b(size - from_bottom, summary);
}