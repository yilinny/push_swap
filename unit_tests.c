#include <stdio.h>
#include "push_swap.h"

void print_arr(int *arr, int length)
{
	int i;
	i = 0;
	while (i < length)
	{
		printf("%d ", arr[i]);
		i++;
	}
}

static int *convert_char_to_int(char **input, int length)
{
	int *final;
	int i;
	final = malloc(length * sizeof(int));
	if (!final)
		return (0);
	i = 0;
	while (i < length)
	{
		final[i] = ft_atoi(input[i]);
		i ++;
	}
	return(final);
}
void print_linked_list (t_list *list)
{
	if(!list)
	{
		printf("NULL");
		return;
	}
	t_list *current;
	current = list;
	while (current != NULL)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
}

void print_moves (t_list *list)
{
	if(!list)
	{
		printf("NULL");
		return;
	}
	t_list *current;
	current = list;
	while (current != NULL)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
}
void print_snapshot(t_snapshot *summary)
{
	printf("\nHere is the current snapshot: \n Stack A: ");
	print_linked_list(summary->stack_a);
	printf("\n Stack B: ");
	print_linked_list(summary->stack_b);
	printf("\n Moves: ");
	print_moves(summary->moves);
}
void del_node(void *content)
{
	free(content);
}
int main (int ac, char *av[])
{
	int *input;
	t_snapshot *summary;
	int smallest_pos;

	input = convert_char_to_int(av + 1, ac -1);
	printf("Input converted to int: ");
	print_arr(input, ac -1);
	printf("\nInput converted to rank, starting from 0\n");
	convert_to_rank(input, ac -1);
	print_arr(input, ac -1);
	summary = init_summary(input, ac -1);
	print_snapshot(summary);
	smallest_pos = sort_stacks(summary, ac - 1, 0);
	//printf("\n -1 if unsorted, position of smallest otherwise: %d", smallest_pos);
	free(input);
	ft_lstclear(&(summary->stack_a), del_node);
	ft_lstclear(&(summary->stack_b), del_node);
	ft_lstclear(&(summary->moves), del_node);
	free(summary);
	
}