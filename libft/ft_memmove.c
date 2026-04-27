/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:59:32 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/02 14:20:05 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	runner;
	int		would_override;

	runner = 0;
	would_override = 1;
	while (runner < n)
	{
		if ((dest + (sizeof(char) * runner)) == src)
			would_override = 0;
		++runner;
	}
	runner = n;
	if (would_override)
	{
		while (0 < runner)
		{
			*((char*)dest + (sizeof(char) * (runner - 1)))
				= *((char*)src + (sizeof(char) * (runner - 1)));
			--runner;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
