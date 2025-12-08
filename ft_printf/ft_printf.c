/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:01:37 by bkhilo            #+#    #+#             */
/*   Updated: 2025/12/08 19:40:21 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_format_handler(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		count;
	size_t	result;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			result = ft_format_handler(format[i + 1], &args);
			i++;
		}
		else
			result = ft_putchar(format[i]);
		if (result == SIZE_MAX)
			return (-1);
		count += (int)result;
		i++;
	}
	va_end(args);
	return (count);
}
