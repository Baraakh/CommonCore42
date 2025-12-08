/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:09:01 by bkhilo            #+#    #+#             */
/*   Updated: 2025/12/08 19:40:17 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putunbr(unsigned int unbr)
{
	size_t		result;
	size_t		tmp;

	result = 0;
	if (unbr > 9)
	{
		tmp = ft_putunbr(unbr / 10);
		if (tmp == SIZE_MAX)
			return (SIZE_MAX);
		result += tmp;
	}
	if (ft_putchar(unbr % 10 + '0') == SIZE_MAX)
		return (SIZE_MAX);
	return (result + 1);
}
