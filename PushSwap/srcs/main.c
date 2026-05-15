#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse_args(argv + 1);
	b = new_stack();
	if (!is_sorted(a))
	{
		if (a->size == 2)
			sort_two(a);
		else if (a->size == 3)
			sort_three(a);
		else if (a->size > 3)
			radix_sort(a, b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
