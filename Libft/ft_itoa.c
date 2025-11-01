/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 01:57:55 by bkhilo            #+#    #+#             */
/*   Updated: 2025/11/01 02:38:26 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_fill_digits(char *dst, int dstlen, int n)
{
	dst[dstlen] = '\0';
	dst--;
	while (n > 0)
	{
		dst[dstlen] = ((n % 10) + '0');
		n /= 10;
		dstlen--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	dnum;
	int		sign;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT32_MIN)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	dnum = ft_count_digits(n);
	result = (char *)malloc((dnum + sign + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (sign)
		result[0] = '-';
	ft_fill_digits(result, (int)dnum + sign, n);
	return (result);
}
