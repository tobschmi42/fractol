/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:21:06 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/27 21:39:38 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static size_t	get_str_size(int num)
{
	size_t	str_size;

	str_size = 0;
	if (num < 0)
		++str_size;
	else if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		++str_size;
	}
	return (str_size);
}

char	*ft_itoa(int n)
{
	size_t	str_size;
	size_t	start;
	char	*out;

	str_size = get_str_size(n);
	start = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	out = ft_calloc((str_size + 1), sizeof(char));
	if (out == NULL)
		return (NULL);
	if (n < 0)
	{
		out[0] = '-';
		n *= -1;
		++start;
	}
	while (start < str_size)
	{
		out[str_size - 1] = n % 10 + '0';
		n /= 10;
		--str_size;
	}
	return (out);
}
