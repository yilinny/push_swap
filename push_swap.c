#include "push_swap.h"

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
int main(int ac, char *av[])
{
	int *input;
	int smallest_pos;
	t_snapshot *summary;
	//input validation 
	input = convert_char_to_int(av + 1, ac - 1);
	convert_to_rank(input, ac - 1);
	summary = init_summary(input, ac -1);
	smallest_pos = sort_stacks(summary, ac -1, 0);  // returns position of smallest in a
	//calculate final -- pushes from b to a in order 
	// print moves 
	// ft lst clear for summary!
	free(input);
	free(summary);
	
}