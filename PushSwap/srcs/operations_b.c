#include "push_swap.h"

void	op_sb(t_stack *b)
{
	do_swap(b);
	write(1, "sb\n", 3);
}

void	op_rb(t_stack *b)
{
	do_rotate(b);
	write(1, "rb\n", 3);
}

void	op_rrb(t_stack *b)
{
	do_rev_rotate(b);
	write(1, "rrb\n", 4);
}
