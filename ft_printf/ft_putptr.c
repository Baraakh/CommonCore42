/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:26:16 by bkhilo            #+#    #+#             */
/*   Updated: 2025/12/08 18:11:21 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_putptr_hex(unsigned long n)
{
	size_t	count;
	size_t	tmp;

	count = 0;
	if (n >= 16)
	{
		tmp = ft_putptr_hex(n / 16);
		if (tmp == SIZE_MAX)
			return (SIZE_MAX);
		count += tmp;
	}
	tmp = ft_putchar("0123456789abcdef"[n % 16]);
	if (tmp == SIZE_MAX)
		return (SIZE_MAX);
	return (count + tmp);
}

size_t	ft_putptr(void *ptr)
{
	size_t			count;
	size_t			tmp;
	unsigned long	addr;

	addr = (unsigned long)ptr;
	count = ft_putstr("0x");
	if (count == SIZE_MAX)
		return (SIZE_MAX);
	tmp = ft_putptr_hex(addr);
	if (tmp == SIZE_MAX)
		return (SIZE_MAX);
	return (count + tmp);
}
