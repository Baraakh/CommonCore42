/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:06:33 by bkhilo            #+#    #+#             */
/*   Updated: 2026/05/15 21:06:36 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

void	op_rra(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rev_rotate(b);
	write(1, "rrb\n", 4);
}
