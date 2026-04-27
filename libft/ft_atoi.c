/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:35:47 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/14 17:06:20 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	out;
	int	is_negative;

	out = 0;
	is_negative = 1;
	while (('\t' <= *nptr && *nptr <= '\r') || *nptr == ' ')
		++nptr;
	if (*nptr == '-')
	{
		++nptr;
		is_negative = -1;
	}
	else if (*nptr == '+')
		++nptr;
	while (ft_isdigit(*nptr))
	{
		out *= 10;
		out += *nptr - '0';
		++nptr;
	}
	out *= is_negative;
	return (out);
}
