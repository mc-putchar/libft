/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:42:37 by mcutura           #+#    #+#             */
/*   Updated: 2024/03/15 15:04:25 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && !(((unsigned char *)(s1))[i] - ((unsigned char *)(s2))[i]))
		++i;
	return ((i != n) * ((unsigned char *)(s1))[i] - ((unsigned char *)(s2))[i]);
}
