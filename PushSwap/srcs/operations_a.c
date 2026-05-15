#include "push_swap.h"

void	op_sa(t_stack *a)
{
	do_swap(a);
	write(1, "sa\n", 3);
}

void	op_ra(t_stack *a)
{
	do_rotate(a);
	write(1, "ra\n", 3);
}

void	op_rra(t_stack *a)
{
	do_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	op_pa(t_stack *a, t_stack *b)
{
	int	val;

	if (b->size == 0)
		return ;
	val = pop_node(b);
	push_node(a, val);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	int	val;

	if (a->size == 0)
		return ;
	val = pop_node(a);
	push_node(b, val);
	write(1, "pb\n", 3);
}
