#include "push_swap.h"

void	op_sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
}

static void	push_node(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

void	op_pa(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		return ;
	push_node(b, a);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	push_node(a, b);
	write(1, "pb\n", 3);
}
