/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:07:17 by bkhilo            #+#    #+#             */
/*   Updated: 2026/05/15 21:07:18 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack *a)
{
	int	pos;
	int	best;
	int	min;

	pos = 0;
	best = 0;
	min = a->index;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			best = pos;
		}
		pos++;
		a = a->next;
	}
	return (best);
}

int	max_pos(t_stack *a)
{
	int	pos;
	int	best;
	int	max;

	pos = 0;
	best = 0;
	max = a->index;
	while (a)
	{
		if (a->index > max)
		{
			max = a->index;
			best = pos;
		}
		pos++;
		a = a->next;
	}
	return (best);
}
