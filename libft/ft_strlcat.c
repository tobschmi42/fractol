/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:41:16 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/07 16:24:16 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	runner;
	size_t	out;

	runner = 0;
	while (dst[runner])
		++runner;
	if (size <= runner)
		return (size + ft_strlen(src));
	out = ft_strlcpy(&dst[runner], src, (size - runner));
	return (out + runner);
}
