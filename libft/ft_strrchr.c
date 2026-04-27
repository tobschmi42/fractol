/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:59:31 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/27 21:50:26 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	runner;

	runner = ft_strlen(s);
	while (0 < runner)
	{
		if (s[runner] == (unsigned char)c)
			return ((char *)&s[runner]);
		--runner;
	}
	if (s[runner] == (unsigned char)c)
		return ((char *)&s[runner]);
	return (NULL);
}
