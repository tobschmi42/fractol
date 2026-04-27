/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:12:02 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/16 16:30:20 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	runner;

	runner = 0;
	if (n == 0)
		return (0);
	while (s1[runner] && s2[runner] && runner < n)
	{
		if (s1[runner] != s2[runner] || runner == n - 1)
			return (s1[runner] - s2[runner]);
		++runner;
	}
	return (s1[runner] - s2[runner]);
}
