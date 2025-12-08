/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:01:31 by bkhilo            #+#    #+#             */
/*   Updated: 2025/12/08 19:40:19 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putptr(void *ptr);
size_t	ft_putnbr(long int n);
size_t	ft_putunbr(unsigned int unbr);
size_t	ft_puthex(unsigned int value, int isupper);

#endif