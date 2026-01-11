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

void swap(int *a, int *b)
{
	int *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_quicksort(int **num_rank_pair, int length)
{
	int i;
	int j;
	
	int *pivot;
	pivot = num_rank_pair[length - 1];
	while (i < length - 1)
	{
		if (num_rank_pair[i][0] > pivot[0])
			
	}
	

}
void	convert_to_rank(int *input)
{
	int **num_rank_pair;
	int i;
	int length;

	i = 0;
	length = 0;
	while (input[length])
		length ++;
	num_rank_pair= malloc(length * sizeof(int*));
	while (i < length)
	{
		num_rank_pair[i] = malloc(2 * sizeof(int));
		num_rank_pair[i][0] = input[i];
		num_rank_pair[i][1] = i;
		i ++;
	}
	ft_quicksort(num_rank_pair, length);
	i = 0;
	while (i < length)
	{
		input[num_rank_pair[i][1]] = i;
		i ++;
	}
}
