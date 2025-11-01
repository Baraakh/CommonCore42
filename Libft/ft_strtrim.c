/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:25:51 by bkhilo            #+#    #+#             */
/*   Updated: 2025/10/31 21:04:41 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (set == NULL)
		return ((char *) s1);
	len = ft_strlen(s1);
	start = 0;
	while (start < len)
	{
		if (ft_strchr(set, s1[start]) == NULL)
			break ;
		start++;
	}
	end = len - 1;
	while (end > start)
	{
		if (ft_strchr(set, s1[end]) == NULL)
			break ;
		end--;
	}
	return (ft_substr(s1, start, (end - start) + 1));
}
