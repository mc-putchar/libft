/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:46:23 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/03 23:26:44 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

extern int	test_ft_strlen_launcher(void);
extern int	test_ft_atoi_launcher(void);
extern int	test_ft_printf_launcher(void);

int	main(int ac, char **av)
{
	int	res;

	if (ac != 1)
		return ((void)av, 1);
	res = 0;
	res |= test_ft_strlen_launcher();
	res |= test_ft_atoi_launcher();
	res |= test_ft_printf_launcher();
	return (res);
}
