/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:43:25 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/27 21:49:33 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	runner;

	runner = 0;
	while (s[runner])
	{
		if (s[runner] == (unsigned char)c)
			return ((char *) &s[runner]);
		++runner;
	}
	if (s[runner] == (unsigned char)c)
		return ((char *) &s[runner]);
	return (NULL);
}
