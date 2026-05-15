/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:07:08 by bkhilo            #+#    #+#             */
/*   Updated: 2026/05/15 21:07:10 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	read_number(char *s, int *i, long *nb)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (!is_digit(s[*i]))
		return (0);
	while (is_digit(s[*i]))
	{
		res = res * 10 + (s[*i] - '0');
		if (res > 2147483648)
			return (0);
		(*i)++;
	}
	*nb = res * sign;
	return (*nb >= INT_MIN && *nb <= INT_MAX);
}

static int	parse_one_arg(char *s, t_stack **a)
{
	int		i;
	int		found;
	long	nb;

	i = 0;
	found = 0;
	while (s[i])
	{
		while (is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		if (!read_number(s, &i, &nb))
			return (0);
		if (s[i] && !is_space(s[i]))
			return (0);
		if (has_duplicate(*a, (int)nb) || !add_back(a, (int)nb))
			return (0);
		found = 1;
	}
	return (found);
}

int	parse_args(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!parse_one_arg(av[i], a))
			return (0);
		i++;
	}
	return (1);
}
