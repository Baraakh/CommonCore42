#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		min_pos;
	int		i;

	cur = a->top;
	min = cur->val;
	min_pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->val < min)
		{
			min = cur->val;
			min_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_pos);
}

static void	rotate_to_min(t_stack *a)
{
	int	pos;

	pos = find_min_pos(a);
	if (pos > 2)
		pos = -(a->size - pos);
	while (pos > 0)
	{
		op_ra(a);
		pos--;
	}
	while (pos < 0)
	{
		op_rra(a);
		pos++;
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	rotate_to_min(a);
	op_pb(a, b);
	rotate_to_min(a);
	op_pb(a, b);
	sort_three(a);
	op_pa(a, b);
	op_pa(a, b);
}
