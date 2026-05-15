#include "push_swap.h"

void	op_ss(t_stack *a, t_stack *b)
{
	do_swap(a);
	do_swap(b);
	write(1, "ss\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	do_rotate(a);
	do_rotate(b);
	write(1, "rr\n", 3);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	do_rev_rotate(a);
	do_rev_rotate(b);
	write(1, "rrr\n", 4);
}
