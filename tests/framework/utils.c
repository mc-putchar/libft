/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:17:49 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/06 23:25:28 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(char const *str)
{
	char	*cpy;
	size_t	size;
	size_t	idx;

	size = 0;
	while (str[size])
		++size;
	cpy = malloc(size);
	if (!cpy)
		return (NULL);
	idx = 0;
	while (size > 4)
	{
		((int *)cpy)[idx] = ((int *)str)[idx];
		idx += 4;
		size -= 4;
	}
	while (size--)
	{
		cpy[idx] = str[idx];
		++idx;
	}
	return (cpy);
}

int	throw_error(int err, const char *msg)
{
	size_t	msglen;

	msglen = 0;
	while (msg[msglen])
		++msglen;
	write(2, msg, msglen);
	return (err);
}
