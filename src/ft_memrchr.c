/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:39:05 by mcutura           #+#    #+#             */
/*   Updated: 2024/03/15 15:04:25 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	while (n--)
		if (((unsigned char *)s)[n] == (unsigned char)c)
			return ((void *)((unsigned char *)s + n));
	if (*(unsigned char *)s == (unsigned char)c)
		return ((void *)s);
	return (NULL);
}
