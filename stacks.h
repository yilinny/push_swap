
typedef struct l_list
{
	void			*content;
	struct l_list	*next;
} t_list;

typedef struct snapshot
{
	struct l_list *stack_a;
	struct l_list *stack_b;
	struct l_list *moves;
} snapshot;

