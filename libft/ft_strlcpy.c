/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:33:47 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/08 19:26:00 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	runner;
	size_t	out;

	runner = 0;
	out = ft_strlen(src);
	if (size == 0)
		return (out);
	while (runner < (size - 1) && src[runner])
	{
		dst[runner] = src[runner];
		++runner;
	}
	dst[runner] = '\0';
	if (!src[runner])
		return (out);
	return (ft_strlen(src));
}
