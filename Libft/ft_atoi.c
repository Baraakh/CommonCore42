/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:00:46 by bkhilo            #+#    #+#             */
/*   Updated: 2025/11/10 23:47:39 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(long num, int digit)
{
	if (num > LONG_MAX / 10)
	{
		return (1);
	}
	if (num > (LONG_MAX - digit) / 10)
	{
		return (1);
	}
	return (0);
}

static int	ft_underflow(long num, int digit)
{
	if (num < LONG_MIN / 10)
	{
		return (1);
	}
	if (num < (LONG_MIN + digit) / 10)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	sum;
	int			i;
	int			sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_overflow(sum, (str[i] - '0')) && sign == 1)
			return (-1);
		else if (ft_underflow(sum, (str[i] - '0')) && sign == -1)
			return (0);
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sign * (int)sum);
}
