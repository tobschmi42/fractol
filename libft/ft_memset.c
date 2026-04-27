/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:06:29 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/09 19:33:42 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	runner;

	runner = 0;
	while (runner < n)
	{
		*((char*)s + (sizeof(char) * runner)) = (char)c;
		++runner;
	}
	return (s);
}
