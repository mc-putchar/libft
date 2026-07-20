/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:07:53 by mcutura           #+#    #+#             */
/*   Updated: 2024/03/16 14:08:48 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static inline size_t	alignment_offset(void const *const ptr)
{
	return ((sizeof(size_t) - ((size_t)ptr % sizeof(size_t))) % sizeof(size_t));
}

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	size_t const	dest_align_offset = alignment_offset(dest);
	size_t const	src_align_offset = alignment_offset(src);
	size_t			i;

	i = 0;
	if (dest_align_offset == src_align_offset)
	{
		while (i < dest_align_offset && i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char const *)src)[i];
			++i;
		}
		while (i + (sizeof(size_t)) <= n)
		{
			*(size_t *)((unsigned char *)dest + i) = \
				*(size_t const *)((unsigned char const *)src + i);
			i += (sizeof(size_t));
		}
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char const *)src)[i];
		++i;
	}
	return (dest);
}
