#include "push_swap.h"

t_stack	*new_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	s->top = NULL;
	s->size = 0;
	return (s);
}

void	push_node(t_stack *s, int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	node->val = val;
	node->next = s->top;
	s->top = node;
	s->size++;
}

int	pop_node(t_stack *s)
{
	t_node	*tmp;
	int		val;

	tmp = s->top;
	val = tmp->val;
	s->top = tmp->next;
	s->size--;
	free(tmp);
	return (val);
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->val > cur->next->val)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	free_stack(t_stack *s)
{
	t_node	*cur;
	t_node	*nxt;

	cur = s->top;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	free(s);
}
