#include "push_swap.h"
static const move_table move_t[] = 
{
	{"ra", "rb", "rr"},
	{"rra", "rrb", "rrr"},
	{"sa", "sb", "ss"}
};

// ---------------------------
// Determine move type index
// 0: ra/rb, 1: rra/rrb, 2: sa/sb
// ---------------------------
static int move_index(const char *move)
{
    if (!move)
        return 0;
    if (ft_strncmp(move, "ra", 2) == 0 || ft_strncmp(move, "rb", 2) == 0)
        return 0;
    if (ft_strncmp(move, "rra", 3) == 0 || ft_strncmp(move, "rrb", 3) == 0)
        return 1;
    if (ft_strncmp(move, "sa", 2) == 0 || ft_strncmp(move, "sb", 2) == 0)
        return 2;
    return 0; // fallback
}
// ---------------------------
// Combine rotations/swaps into condensed moves
// ---------------------------
static void combine_moves(t_list **new_moves, int index, int *count_a, int *count_b)
{
    if (index == -1)
        return;
    // Add combined moves first (e.g., rr, rrr, ss)
    while (*count_a > 0 && *count_b > 0)
    {
        ft_lstadd_back(new_moves, ft_lstnew(ft_strdup(move_t[index].combined)));
        (*count_a)--;
        (*count_b)--;
    }

    // Add remaining moves for stack A
    while (*count_a > 0)
    {
        ft_lstadd_back(new_moves, ft_lstnew(ft_strdup(move_t[index].a_move)));
        (*count_a)--;
    }

    // Add remaining moves for stack B
    while (*count_b > 0)
    {
        ft_lstadd_back(new_moves, ft_lstnew(ft_strdup(move_t[index].b_move)));
        (*count_b)--;
    }
}
// ---------------------------
// Condense moves in snapshot
// Automatically handles ra/rb, rra/rrb, sa/sb and pushes
// ---------------------------
void condense_moves(t_snapshot *summary)
{
    if (!summary || !summary->moves)
        return;

    t_list *old_moves = summary->moves;
    t_list *new_moves = NULL;
    int count_a = 0;
    int count_b = 0;
    int index = -1;
    int len;

    while (old_moves)
    {
        char *move;

        move = (char *)old_moves->content;
        if (move[0] == 'p') // push move triggers condensation
        {
            combine_moves(&new_moves, index, &count_a, &count_b);
            ft_lstadd_back(&new_moves, ft_lstnew(ft_strdup(move)));
        }
        else
        {
            index = move_index(move);
            // count consecutive moves by stack type
            len = ft_strlen(move);
            if (move[len - 1] == 'a')
                count_a++;
            else
                count_b++;
        }
        old_moves = old_moves->next;
    }

    // Handle leftover rotations at the end
    if (count_a > 0 || count_b > 0)
        combine_moves(&new_moves, index, &count_a, &count_b);
    // Free old move list safely
    old_moves = summary->moves;
    while (old_moves)
    {
        t_list *tmp = old_moves->next;
        free(old_moves->content);
        free(old_moves);
        old_moves = tmp;
    }

    // Replace moves with condensed list
    summary->moves = new_moves;
}
static int find_biggest(t_list *stack_b)
{
	int max;
	int pos;
	int max_pos;
	t_list *curr;

	curr = stack_b;
	max = -1;
	pos = 0;
	while (curr)
	{
		if (*(int *)(curr -> content) > max)
		{
			max = *(int *)(curr -> content);
			max_pos = pos;
		}
		curr = curr -> next;
		pos ++;
	}
	return(max_pos);
}
void final_sort(t_snapshot *summary, int smallest_a)
{
	int biggest_b;
	biggest_b = find_biggest(summary->stack_b);
	pos_to_top(smallest_a, 'a', summary);
	pos_to_top (biggest_b, 'b', summary);
	//condense_moves(summary);
	while (summary -> stack_b != NULL)
		alter_summary (summary, "pa");
}

