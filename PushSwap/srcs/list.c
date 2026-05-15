#include "push_swap.h"

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

int	add_back(t_stack **a, int value)
{
	t_stack	*node;
	t_stack	*cur;

	node = new_node(value);
	if (!node)
		return (0);
	if (!*a)
	{
		*a = node;
		return (1);
	}
	cur = *a;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
	return (1);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

int	stack_size(t_stack *a)
{
	int	size;

	size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}
