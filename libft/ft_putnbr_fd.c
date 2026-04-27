/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:02:00 by tobschmi          #+#    #+#             */
/*   Updated: 2025/10/27 18:28:31 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	putnbr_rec(int num, int fd)
{
	if (num == 0)
		return ;
	putnbr_rec(num / 10, fd);
	num = (num % 10) + '0';
	write(fd, &num, sizeof(char));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", sizeof(char));
	else if (0 < n)
		putnbr_rec(n, fd);
	else if (n < 0)
	{
		write(fd, "-", sizeof(char));
		putnbr_rec(n / -10, fd);
		n = ((n % 10) * -1) + '0';
		write(fd, &n, sizeof(char));
	}
}
