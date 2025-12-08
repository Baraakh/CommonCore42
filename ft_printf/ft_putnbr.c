/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:55:33 by bkhilo            #+#    #+#             */
/*   Updated: 2025/12/08 19:40:18 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(long int n)
{
	size_t		result;
	size_t		tmp;

	result = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == SIZE_MAX)
			return (SIZE_MAX);
		n *= -1;
		result++;
	}
	if (n > 9)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == SIZE_MAX)
			return (SIZE_MAX);
		result += tmp;
	}
	if (ft_putchar(n % 10 + '0') == SIZE_MAX)
		return (SIZE_MAX);
	return (result + 1);
}
