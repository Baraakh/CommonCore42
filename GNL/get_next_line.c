/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:02:12 by bkhilo            #+#    #+#             */
/*   Updated: 2025/11/28 09:18:57 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		newline_index = 0;
		while ((*current_line)[newline_index] != '\n'
			&& (*current_line)[newline_index] != '\0')
			newline_index++;
		if ((*current_line)[newline_index] == '\n')
			return (ft_substr_resolve(current_line, newline_index));
		tmp = (*current_line);
		(*current_line) = NULL;
		return (tmp);
	}
	return (NULL);
}

char	*join_and_check(char **current_line, char *buffer)
{
	char	*tmp;
	size_t	newline_index;

	tmp = ft_strjoin((*current_line), buffer);
	if (tmp == NULL)
	{
		free((*current_line));
		(*current_line) = NULL;
		return (NULL);
	}
	free((*current_line));
	(*current_line) = tmp;
	newline_index = 0;
	while ((*current_line)[newline_index] != '\n'
		&& (*current_line)[newline_index] != '\0')
		newline_index++;
	if ((*current_line)[newline_index] == '\n')
		return (ft_substr_resolve(current_line, newline_index));
	return (tmp);
}

char	*process_next_line(int fd, char **current_line, char *buffer
	, size_t bytes_read)
{
	char	*result;

	while (bytes_read > 0)
	{
		result = join_and_check(current_line, buffer);
		if (result == NULL || result != (*current_line))
		{
			free(buffer);
			return (result);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == SIZE_MAX)
		{
			free(buffer);
			free((*current_line));
			(*current_line) = NULL;
			return (NULL);
		}
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
	char		test;

	if (fd < 0 || read(fd, &test, 0) == -1 || BUFFER_SIZE < 0
		|| BUFFER_SIZE > SIZE_MAX)
	{
		free(current_line);
		current_line = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == SIZE_MAX)
	{
		free(buffer);
		free(current_line);
		current_line = NULL;
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (process_next_line(fd, &current_line, buffer, bytes_read));
}
