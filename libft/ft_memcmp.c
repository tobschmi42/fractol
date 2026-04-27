/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:53:54 by tobschmi          #+#    #+#             */
/*   Updated: 2025/11/03 12:08:54 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;
	size_t				runner;

	string1 = (const unsigned char *) s1;
	string2 = (const unsigned char *) s2;
	runner = 0;
	if (n == 0)
		return (0);
	while (runner < n)
	{
		if (string1[runner] != string2[runner])
			return (string1[runner] - string2[runner]);
		++runner;
	}
	return (0);
}
