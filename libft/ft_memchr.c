/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:28:34 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/27 22:04:09 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*string;
	size_t				runner;

	string = (const unsigned char *) s;
	runner = 0;
	while (runner < n)
	{
		if (string[runner] == (unsigned char)c)
			return ((void *)(string + runner));
		++runner;
	}
	return (NULL);
}
