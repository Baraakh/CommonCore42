#include "push_swap.h"

static void	run_sort(t_stack **a, t_stack **b)
{
	int	size;

	set_indexes(*a);
	size = stack_size(*a);
	if (size <= 6)
		sort_small(a, b, size);
	else
		sort_chunk(a, b, size);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!parse_args(ac, av, &a))
	{
		free_stack(&a);
		put_error();
		return (1);
	}
	if (!is_sorted(a))
		run_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
