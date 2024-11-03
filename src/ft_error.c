/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:12:04 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/03 01:25:10 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	throw_error(int err, char const *msg)
{
	(void)ft_dprintf(2, "%s\n", msg);
	return (err);
}

void	print_error(char const *msg)
{
	(void)ft_dprintf(2, "%s\n", msg);
}
