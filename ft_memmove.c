/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:22:54 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/03 11:23:08 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == dest)
		return (dest);
	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			++i;
		}
	}
	else
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
