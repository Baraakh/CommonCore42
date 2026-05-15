#include "push_swap.h"

static int	valid_int(char *s)
{
	long	n;
	int		i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i = 1;
	if (!s[i])
		return (0);
	n = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		n = n * 10 + (s[i] - '0');
		if (n > (long)2147483648)
			return (0);
		i++;
	}
	if (s[0] != '-' && n > (long)2147483647)
		return (0);
	return (1);
}

static int	has_dup(t_stack *a, int val)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->val == val)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static long	ft_atol(char *s)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	n = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

static void	push_from_arr(t_stack *a, char **arr, int n)
{
	int		i;
	long	v;

	i = n - 1;
	while (i >= 0)
	{
		if (!valid_int(arr[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		v = ft_atol(arr[i]);
		if (has_dup(a, (int)v))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		push_node(a, (int)v);
		i--;
	}
}

t_stack	*parse_args(char **argv)
{
	t_stack	*a;
	char	**arr;
	int		n;
	int		is_split;

	a = new_stack();
	is_split = 0;
	arr = argv;
	if (argv[0] && !argv[1])
	{
		arr = split_str(argv[0]);
		is_split = 1;
	}
	n = 0;
	while (arr[n])
		n++;
	push_from_arr(a, arr, n);
	if (is_split)
		free_split(arr);
	return (a);
}
