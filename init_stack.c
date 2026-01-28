/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:24:38 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/01/11 13:24:44 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int **a, int **b)
{
	int *temp;
	if (*a == *b)
		return;
	temp = *a;
	*a = *b;
	*b = temp;
}

int ft_partition(int **num_rank_pair, int start, int end)
{
	int i;
	int j;
	
	int *pivot;
	pivot = num_rank_pair[end];
	i = start;
	j = start;

	while (i < end)
	{
		if (num_rank_pair[i][0] < pivot[0])
		{
			swap(&num_rank_pair[i], &num_rank_pair[j]);
			j ++;
		}
		i ++;	
	}
	swap(&num_rank_pair[j], &num_rank_pair[end]);
	return (j);
}

void ft_quicksort (int **num_rank_pair, int start, int end)
{
	int pivot_index;
	if (start < end)
	{
		pivot_index = ft_partition(num_rank_pair, start, end);

		ft_quicksort(num_rank_pair, start, pivot_index - 1);
		ft_quicksort(num_rank_pair, pivot_index + 1, end);
	}
}

void	convert_to_rank(int *input, int length)
{
	// use argv argc for length and pass it in
	int **num_rank_pair;
	int i;

	i = 0;
	num_rank_pair= malloc(length * sizeof(int*));
	if (!num_rank_pair)
		return;
	while (i < length)
	{
		num_rank_pair[i] = malloc(2 * sizeof(int));
		if (!num_rank_pair[i])
			return;
		num_rank_pair[i][0] = input[i];
		num_rank_pair[i][1] = i;
		i ++;
	}
	ft_quicksort(num_rank_pair, 0, length -1);
	i = 0;
	while (i < length)
	{
		input[num_rank_pair[i][1]] = i;
		free(num_rank_pair[i]);
		i ++;
	}
	free(num_rank_pair);
}
