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

#include "libft.h"

static void	ft_putn(int n, int fd)
{
	if (!n)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n < -9)
			ft_putn(n / 10 * -1, fd);
		ft_putchar_fd(n % 10 * -1 + '0', fd);
	}
	else
	{
		if (n > 9)
			ft_putn(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!n)
		ft_putchar_fd('0', fd);
	else
		ft_putn(n, fd);
}
