/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:53:32 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/20 17:09:38 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	runner;
	size_t	start;
	size_t	end;

	runner = 0;
	while (s1[runner] && ft_strchr(set, s1[runner]) != NULL)
		++runner;
	start = runner;
	if (start == ft_strlen(s1))
		return (ft_calloc(1, 1));
	runner = ft_strlen(s1) - 1;
	while (start < runner && ft_strchr(set, s1[runner]) != NULL)
		--runner;
	end = (runner - start) + 1;
	return (ft_substr(s1, (unsigned int)start, end));
}
