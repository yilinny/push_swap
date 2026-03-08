#include "push_swap.h"
void error_exit()
{
	write(2, "Error\n", 6);
	exit (1);
}


static void del_node(void *content)
{
	free(content);
}

void print_moves (t_list *moves)
{
	t_list *curr;

	curr = moves;
	while (curr)
	{
		ft_printf("%s\n", (char *)(curr->content));
		curr = curr ->next;
	}
}

int main(int ac, char *av[])
{
	int *input;
	int smallest_pos;
	int length;
	t_snapshot *summary;

	if (ac != 2)
		error_exit();
	input = convert_char_to_int(av[1], &length);
	convert_to_rank(input, length);
	summary = init_summary(input, length);
	smallest_pos = sort_stacks(summary, length, 0);
	final_sort(summary, smallest_pos);
	print_moves(summary->moves);
	free(input);
	ft_lstclear(&(summary->stack_a), del_node);
	ft_lstclear(&(summary->stack_b), del_node);
	ft_lstclear(&(summary->moves), del_node);
	free(summary);
}