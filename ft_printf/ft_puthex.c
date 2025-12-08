/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:27:42 by bkhilo            #+#    #+#             */
/*   Updated: 2025/12/08 18:01:22 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex(unsigned int value, int isupper)
{
	size_t	count;
	size_t	tmp;
	char	*base;

	count = 0;
	if (isupper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (value >= 16)
	{
		tmp = ft_puthex(value / 16, isupper);
		if (tmp == SIZE_MAX)
			return (SIZE_MAX);
		count += tmp;
	}
	tmp = ft_putchar(base[value % 16]);
	if (tmp == SIZE_MAX)
		return (SIZE_MAX);
	return (count + tmp);
}
