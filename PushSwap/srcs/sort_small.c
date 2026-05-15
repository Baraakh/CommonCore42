#include "push_swap.h"

static void	sort_three_ops(t_stack *a, int top, int mid, int bot)
{
	if (top > mid && mid < bot && top < bot)
		op_sa(a);
	else if (top < mid && top < bot && mid > bot)
	{
		op_rra(a);
		op_sa(a);
	}
	else if (top > mid && mid < bot && top > bot)
		op_ra(a);
	else if (top < mid && top > bot)
		op_rra(a);
	else if (top > mid && mid > bot)
	{
		op_sa(a);
		op_rra(a);
	}
}

void	sort_two(t_stack *a)
{
	if (a->top->val > a->top->next->val)
		op_sa(a);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->val;
	mid = a->top->next->val;
	bot = a->top->next->next->val;
	sort_three_ops(a, top, mid, bot);
}
