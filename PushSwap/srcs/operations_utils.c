#include "push_swap.h"

void	do_swap(t_stack *s)
{
	t_node	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->top;
	s->top = tmp->next;
	tmp->next = s->top->next;
	s->top->next = tmp;
}

void	do_rotate(t_stack *s)
{
	t_node	*tmp;
	t_node	*last;

	if (s->size < 2)
		return ;
	tmp = s->top;
	s->top = s->top->next;
	tmp->next = NULL;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	do_rev_rotate(t_stack *s)
{
	t_node	*tmp;
	t_node	*prev;

	if (s->size < 2)
		return ;
	tmp = s->top;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = s->top;
	s->top = tmp;
}
