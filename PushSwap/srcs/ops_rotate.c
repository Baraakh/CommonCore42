#include "push_swap.h"

static void	rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	op_ra(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}
