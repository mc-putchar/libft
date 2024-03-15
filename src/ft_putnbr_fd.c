/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:00:52 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/03 16:25:19 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	res;
	int		d;
	char	c;

	if (!n)
		return (write(fd, "0", 1));
	res = 0;
	if (n < 0)
	{
		res += write(fd, "-", 1);
		n = -n;
	}
	while (n > 9)
	{
		d = n;
		while (d > 9)
			d /= 10;
		n -= d;
		c = '0' + d;
		res += write(fd, &c, 1);
	}
	return (res);
}
