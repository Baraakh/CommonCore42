/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 03:37:54 by bkhilo            #+#    #+#             */
/*   Updated: 2025/12/08 17:55:32 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(char *s)
{
	size_t	len;

	if (s == NULL)
		return (ft_putstr("(null)"));
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}
