/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:47:55 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/20 13:54:15 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **array, int index)
{
	int	j;

	j = 0;
	while (j < index)
	{
		free(array[j]);
		j++;
	}
}

static int	get_count(char const *s, char c)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (s[index])
	{
		if (count == 0 && s[index] != c)
			count ++;
		if (s[index] == c && s[index + 1] && s[index + 1] != c)
			count++;
		index++;
	}
	return (count);
}

static int	populate_final(int count, char const *s, char c, char **final)
{
	int		index;
	char	*next;
	char	*last;

	last = (char *)s;
	index = 0;
	while (index < count)
	{
		next = ft_strchr(last, c);
		while (next != NULL && next == last)
		{
			last = next + 1;
			next = ft_strchr(last, c);
		}
		if (next == NULL)
			next = last + ft_strlen(last);
		final[index] = (char *)malloc(next - last + 1);
		if (final[index] == NULL)
			return (index);
		ft_strlcpy(final[index], last, next - last + 1);
		last = next + 1;
		index++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	int		count;

	if (!s)
		return (NULL);
	count = get_count(s, c);
	final = (char **)malloc((count + 1) * sizeof(char *));
	if (final == NULL)
		return (NULL);
	if (populate_final(count, s, c, final))
	{
		free_split(final, populate_final(count, s, c, final));
		free (final);
		return (NULL);
	}
	final[count] = NULL;
	return (final);
}
