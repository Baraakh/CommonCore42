/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:08:41 by bkhilo            #+#    #+#             */
/*   Updated: 2026/05/15 21:08:43 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		op_sa(a);
	else if (first > second && second > third)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (first > second && second < third && first > third)
		op_ra(a);
	else if (first < second && second > third && first < third)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (first < second && second > third && first > third)
		op_rra(a);
}

static void	move_min_to_b(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	pos = min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			op_ra(a);
	else
		while (pos++ < size)
			op_rra(a);
	op_pb(a, b);
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		op_sa(a);
		return ;
	}
	while (size > 3)
	{
		move_min_to_b(a, b);
		size--;
	}
	if (!is_sorted(*a))
		sort_three(a);
	while (*b)
		op_pa(a, b);
}
