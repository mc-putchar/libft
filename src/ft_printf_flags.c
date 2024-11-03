/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:49:48 by mcutura           #+#    #+#             */
/*   Updated: 2024/06/22 04:04:37 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

int	process_printf_flags(t_format *f)
{
	char	*tmp;

	if (f->flags & PREFIX_SIGN && (f->specifier == 2 || f->specifier == 3))
	{
		if (ft_isdigit(f->out[0]))
		{
			tmp = ft_strjoin("+", f->out);
			if (!tmp)
				return (-1);
			free(f->out);
			f->out = tmp;
		}
	}
	return (0);
}

char	*make_padding(t_format *f)
{
	char		*pad;
	int			i;

	pad = malloc(f->width);
	if (!pad)
		return (-1);
	if (f->flags & LEFT_ALIGN)
	{
		i = f->len;
		ft_memcpy(pad, f->out, i);
		while (i < f->width)
			pad[i++] = ' ';
	}
	else
	{
		i = 0;
		while (i < f->width - f->len)
			pad[i++] = ' ';
		ft_memcpy(pad + i, f->out, f->len);
	}
	free(f->out);
	f->out = pad;
	f->len = f->width;
	return (0);
}
