/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:17:55 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/09 19:34:04 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	runner;

	runner = 0;
	while (runner < n)
	{
		*((char*)dest + (sizeof(char) * runner))
			= *((char*)src + (sizeof(char) * runner));
		++runner;
	}
	return (dest);
}
