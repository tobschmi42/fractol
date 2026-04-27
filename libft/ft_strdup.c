/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:53:40 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/16 15:38:34 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	str_size;
	char	*dup;
	size_t	runner;

	str_size = ft_strlen(s);
	dup = malloc(sizeof(char) * (str_size + 1));
	runner = 0;
	if (dup == NULL)
		return (NULL);
	while (s[runner])
	{
		dup[runner] = s[runner];
		++runner;
	}
	dup[runner] = '\0';
	return (dup);
}
