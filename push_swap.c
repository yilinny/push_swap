#include "push_swap.h"

static int *convert_char_to_int(char *input, int length)
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
	//input validation 
	input = convert_char_to_int(av, ac - 1);
	convert_to_rank(input, ac - 1);
	smallest = sort_stacks(current);

	free(input);
	
}