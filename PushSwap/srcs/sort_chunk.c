/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:07:25 by bkhilo            #+#    #+#             */
/*   Updated: 2026/05/15 21:07:27 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (35);
}

static void	push_to_b(t_stack **a, t_stack **b, int size)
{
	int	limit;
	int	chunk;

	limit = 0;
	chunk = chunk_size(size);
	while (*a)
	{
		if ((*a)->index <= limit)
		{
			op_pb(a, b);
			op_rb(b);
			limit++;
		}
		else if ((*a)->index <= limit + chunk)
		{
			op_pb(a, b);
			limit++;
		}
		else
			op_ra(a);
	}
}

static void	move_max_to_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	pos = max_pos(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
		while (pos-- > 0)
			op_rb(b);
	else
		while (pos++ < size)
			op_rrb(b);
	op_pa(a, b);
}

void	sort_chunk(t_stack **a, t_stack **b, int size)
{
	push_to_b(a, b, size);
	while (*b)
		move_max_to_a(a, b);
}
