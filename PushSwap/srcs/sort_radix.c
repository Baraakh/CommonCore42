#include "push_swap.h"

static int	*make_arr(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i] = cur->val;
		cur = cur->next;
		i++;
	}
	return (arr);
}

static void	sort_arr(int *arr, int n)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < n)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
		i++;
	}
}

static void	normalize(t_stack *a)
{
	int		*arr;
	int		*sorted;
	t_node	*cur;
	int		i;
	int		j;

	arr = make_arr(a);
	sorted = make_arr(a);
	sort_arr(sorted, a->size);
	cur = a->top;
	i = 0;
	while (cur)
	{
		j = 0;
		while (sorted[j] != arr[i])
			j++;
		cur->val = j;
		cur = cur->next;
		i++;
	}
	free(arr);
	free(sorted);
}

static void	do_pass(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if ((a->top->val >> bit) & 1)
			op_ra(a);
		else
			op_pb(a, b);
		i++;
	}
	while (b->size)
		op_pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;

	normalize(a);
	max_bits = 0;
	while ((1 << max_bits) < a->size)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		do_pass(a, b, bit);
		bit++;
	}
}
