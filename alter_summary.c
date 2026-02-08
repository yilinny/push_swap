#include "push_swap.h"
static const stack_table handle_move[] = 
{
	{"sa", swap_stack},
	{"sb", swap_stack},
	{"pa", push_stack},
	{"pb", push_stack},
	{"ra", rotate_stack},
	{"rb", rotate_stack},
	{"rra", reverse_rotate_stack},
	{"rrb", reverse_rotate_stack}
};

void alter_summary(t_snapshot *summary, char *move)
{
	t_list **param_1;
	t_list **param_2;
	int i;

	i = 0;
	ft_lstadd_back(&(summary->moves), ft_lstnew(move));
	if (move[ft_strlen(move) -1] == 'a')
	{
		param_1 = &(summary->stack_a);
		param_2 = &(summary->stack_b);
	}
	else
	{
		param_1 = &(summary->stack_b);
		param_2 = &(summary->stack_a);
	}
	while (i < 8 && ft_strncmp(move, handle_move[i].move, 3))
		i ++;
	if (i < 8)
		handle_move[i].func(param_1, param_2);
}