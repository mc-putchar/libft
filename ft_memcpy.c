/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:07:53 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:09 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned char	*ptr;

	ptr = dest;
	if (!src && !dest)
		return (NULL);
	while (n--)
		*ptr++ = *(unsigned char *)src++;
	return (dest);
}
