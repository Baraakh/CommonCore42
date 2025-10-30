/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 03:41:54 by bkhilo            #+#    #+#             */
/*   Updated: 2025/10/30 03:57:05 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*result;

	ch = (char)c;
	result = NULL;
	while (*s != '\0')
	{
		if (*s == ch)
			result = (char *)s;
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (result);
}
