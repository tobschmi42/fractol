/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:11:08 by tobschmi          #+#    #+#             */
/*   Updated: 2025/11/06 15:38:19 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	size_t	strlen1;
	size_t	strlen2;

	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	if ((ft_strlen(s1) + ft_strlen(s2) == 0)
		|| strlen1 == SIZE_MAX
		|| strlen2 > SIZE_MAX - strlen1 - 1)
		return (ft_calloc(1, 1));
	joined_string = malloc((strlen1 + strlen2 + 1) * sizeof(char));
	if (joined_string == NULL)
		return (NULL);
	ft_strlcpy(joined_string, s1, strlen1 + 1);
	ft_strlcat(joined_string, s2, strlen1 + strlen2 + 1);
	return (joined_string);
}
