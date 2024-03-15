/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:07:53 by mcutura           #+#    #+#             */
/*   Updated: 2024/03/15 15:04:25 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i && n - i >= (sizeof(int)))
	{
		((int *)dest)[i / (sizeof(int))] = ((int *)src)[i / (sizeof(int))];
		i += (sizeof(int));
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}
