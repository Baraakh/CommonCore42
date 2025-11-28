/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:02:12 by bkhilo            #+#    #+#             */
/*   Updated: 2025/11/28 05:42:47 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_newline(const char *s, size_t *index)
{
	(*index) = 0;
	while (*s != '\n' && *s != '\0')
	{
		(*index)++;
		s++;
	}
	if (*s == '\n')
		return (1);
	return (0);
}

char	*ft_substr_resolve(char **current_line, size_t index)
{
	char	*next_line;
	char	*new_current_line;
	size_t	extralen;
	size_t	i;

	next_line = ft_substr((*current_line), 0, index + 1);
	if (next_line == NULL)
	{
		free((*current_line));
		(*current_line) = NULL;
		return (NULL);
	}
	extralen = 0;
	i = index + 1;
	while ((*current_line)[i] != '\0')
	{
		extralen++;
		i++;
	}
	new_current_line = ft_substr((*current_line), index + 1, extralen);
	free((*current_line));
	(*current_line) = new_current_line;
	return (next_line);
}

char	*ft_handle_rest(char **current_line)
{
	char	*tmp;
	size_t	newline_index;

	if ((*current_line) != NULL)
	{
		if (ft_check_newline((*current_line), &newline_index))
			return (ft_substr_resolve(current_line, newline_index));
		else
		{
			tmp = (*current_line);
			(*current_line) = NULL;
			return (tmp);
		}
	}
	return (NULL);
}

char	*process_next_line(int fd, char **current_line, char *buffer
	, size_t bytes_read)
{
	char	*tmp;
	size_t	newline_index;

	while (bytes_read > 0)
	{
		tmp = ft_strjoin((*current_line), buffer);
		if ((*current_line) != NULL)
			free((*current_line));
		(*current_line) = tmp;
		if (ft_check_newline((*current_line), &newline_index))
		{
			free(buffer);
			return (ft_substr_resolve(current_line, newline_index));
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}
	free(buffer);
	return (ft_handle_rest(current_line));
}

char	*get_next_line(int fd)
{
	static char	*current_line;
	char		*buffer;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > SIZE_MAX)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	if (bytes_read > 0 && current_line == NULL)
	{
		current_line = (char *)malloc(sizeof(char));
		if (current_line == NULL)
			return (NULL);
		current_line = NULL;
	}
	return (process_next_line(fd, &current_line, buffer, bytes_read));
}
