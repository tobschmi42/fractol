/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:33:39 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/27 21:58:15 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_strings(char const *s, char c)
{
	size_t	count;
	int		new_str;

	count = 0;
	new_str = 1;
	while (*s)
	{
		if (*s == c)
			new_str = 1;
		else if (*s != c && new_str)
		{
			++count;
			new_str = 0;
		}
		++s;
	}
	return (count);
}

static size_t	substrlen(char const *s, char c)
{
	size_t	runner;

	runner = 0;
	while (s[runner] != c && s[runner])
		++runner;
	return (runner);
}

static char	**free_list(char **list)
{
	size_t	runner;

	runner = 0;
	while (list[runner] != NULL)
	{
		free(list[runner]);
		++runner;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	runner;
	size_t	str_count;
	size_t	count;
	char	**split;

	runner = 0;
	str_count = count_strings(s, c);
	count = 0;
	split = malloc((str_count + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split[str_count] = NULL;
	while (count < str_count)
	{
		while (s[runner] == c)
			++runner;
		split[count] = ft_substr(s, runner, substrlen(&s[runner], c));
		if (split[count] == NULL)
			return (free_list(split));
		++count;
		runner += substrlen(&s[runner], c);
	}
	return (split);
}
