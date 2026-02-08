#include "push_swap.h"
static t_list *ft_lstnew_int(int a)
{
	t_list *final;
	int *val;

	final = malloc(sizeof(t_list));
	if (!final)
		return(NULL);
	val = malloc(sizeof(int));
    if (!val)
    {
        free(final);
        return NULL;
    }
    *val = a;
	final-> content = val;
	final -> next = NULL;
	return (final);
}

t_snapshot *init_summary (int *input, int length)
{
    int i;
    t_list *stack_a;
    t_snapshot *all;

    if (!input || length <= 0)
        return (NULL);

    all = malloc(sizeof(t_snapshot));
    if (!all )
        return (NULL);
    stack_a = ft_lstnew_int(input[0]);
    i = 1;
    while (i < length)
    {
        ft_lstadd_back(&stack_a, ft_lstnew_int(input[i]));
        i++;
    }
    all->stack_a = stack_a;
    all->stack_b = NULL;
    all->moves = NULL;
    return (all);
}

