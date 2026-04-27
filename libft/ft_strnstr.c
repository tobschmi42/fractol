/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:06:33 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/09 19:32:16 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	runner;
	size_t	little_size;
	size_t	checker;

	runner = 0;
	if (!ft_strlen(little))
		return ((char *) big);
	little_size = ft_strlen(little);
	while (runner + little_size - 1 < len && big[runner])
	{
		checker = 0;
		while (big[runner + checker] && little[checker])
		{
			if (big[runner + checker] != little[checker])
				break ;
			++checker;
		}
		if (checker == little_size)
			return ((char *) &big[runner]);
		++runner;
	}
	return (NULL);
}
