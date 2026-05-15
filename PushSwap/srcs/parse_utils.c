#include "push_swap.h"

static int	count_words(char *s)
{
	int	n;
	int	in;

	n = 0;
	in = 0;
	while (*s)
	{
		if (*s == ' ')
			in = 0;
		else if (!in)
		{
			in = 1;
			n++;
		}
		s++;
	}
	return (n);
}

static char	*get_word(char *s, int start, int len)
{
	char	*w;
	int		i;

	w = malloc(len + 1);
	if (!w)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (i < len)
	{
		w[i] = s[start + i];
		i++;
	}
	w[len] = '\0';
	return (w);
}

static void	fill_split(char **arr, char *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		j = i;
		while (s[j] && s[j] != ' ')
			j++;
		arr[k] = get_word(s, i, j - i);
		k++;
		i = j;
	}
	arr[k] = NULL;
}

char	**split_str(char *s)
{
	char	**arr;

	arr = malloc(sizeof(char *) * (count_words(s) + 1));
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	fill_split(arr, s);
	return (arr);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
