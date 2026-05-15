#include "push_swap.h"

void	put_error(void)
{
	write(2, "Error\n", 6);
}

int	has_duplicate(t_stack *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	set_indexes(t_stack *a)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		index;

	cur = a;
	while (cur)
	{
		index = 0;
		cmp = a;
		while (cmp)
		{
			if (cmp->value < cur->value)
				index++;
			cmp = cmp->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}
