#include "push_swap.h"
void pos_to_top (int pos, char stack, t_snapshot *summary)
{
	int length;
	if (stack == 'a')
		length = ft_lstsize(summary->stack_a);
	else
		length = ft_lstsize(summary->stack_b);
	
	if (pos == 0)
		return;
	if (pos == 1 && stack == 'a')
	{
		alter_summary(summary, "sa");
		return;
	}
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