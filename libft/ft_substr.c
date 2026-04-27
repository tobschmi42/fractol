/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:40:36 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/20 16:29:59 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substring_size;
	char	*substring;

	if (ft_strlen(s) <= start || len == 0)
		return (ft_calloc(1, 1));
	substring_size = ft_strlen(&s[start]) + 1;
	if (len < substring_size)
		substring_size = len + 1;
	substring = malloc(substring_size * sizeof(char));
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, &s[start], substring_size);
	return (substring);
}
