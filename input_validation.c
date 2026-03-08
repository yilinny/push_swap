#include "push_swap.h"
#include "limits.h"

static int check_dup(int length, int *input)
{
	int seen[];
	int i;

	ft_bzero(seen, sizeof(seen));
	i = 0;
	while (i < length)
	{
		if (seen[input[i]] == 1)
			return(1);
		seen[input[i]] = 1;
		i ++;
	}
	return(0);
}
static long long_ftatoi(char *str)
{
	long		final;
	long		sign;

	final = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		final = (final * 10) + (*str - '0');
		str++;
	}
	return (final * sign);
}
static int is_atoi_safe(char *s)
{
	char *str;
	str = s;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <='9')
		str ++;
	if (*str < '0' || *str > '9')
		error_exit();
	if (long_ftatoi(s) > INT_MAX || long_ftatoi(s) < INT_MIN)
		error_exit();
	return(0);
}

int *convert_char_to_int(char *input, int *length)
{
	int *final;
	char **input_c;
	int i;
	int j;

	input_c = ft_split(input, ' ');
	if (input_c == NULL)
		error_exit();
	i = 0;
	while (input_c[i])
		i ++;
	final = malloc(i * sizeof(int));
	i = 0;
	while (input_c[i])
	{
		if (is_atoi_safe(input_c[i]))
			error_exit();
		final[i] = ft_atoi(input_c[i]);
		i ++;
	}
	*length = i;
	if (check_dup(i, final))
		error_exit();
	return(final);
}