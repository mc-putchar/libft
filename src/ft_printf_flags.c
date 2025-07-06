/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:49:48 by mcutura           #+#    #+#             */
/*   Updated: 2025/07/06 02:32:55 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

static int	process_prefix(t_format *f)
{
	char		*tmp;

	if (ft_isdigit(f->out[0]))
	{
		if (f->flags & PREFIX_SIGN)
			tmp = ft_strjoin("+", f->out);
		else
			tmp = ft_strjoin(" ", f->out);
		if (!tmp)
			return (-1);
		free(f->out);
		f->out = tmp;
		f->len = ft_strlen(tmp);
	}
	return (0);
}

static int	zero_padding(t_format *f)
{
	int const	off = (f->out[0] == '-' || f->out[0] == '+') \
		+ (((f->flags & ALT_FORM) != 0) * 2);
	int			i;
	int			size;
	char		*pad;

	size = (int)f->len;
	if (f->width > size && f->precision < 0)
		size = f->width;
	else
		return (0);
	if (safe_alloc(&pad, size + 1))
		return (-1);
	i = -1;
	while (++i < off)
		pad[i] = f->out[i];
	while (i < size - (int)f->len + off)
		pad[i++] = '0';
	ft_memmove(pad + i, f->out + off, f->len - off);
	pad[size] = 0;
	free(f->out);
	f->out = pad;
	f->len = ft_strlen(pad);
	return (0);
}

static int	space_padding(t_format *f)
{
	char		*pad;
	int			i;
	int			size;

	size = (int)f->len;
	if ((int)f->len < f->width)
		size = f->width;
	if (safe_alloc(&pad, size + 1))
		return (-1);
	i = 0;
	if (!(f->flags & LEFT_ALIGN))
		while (i < size - (int)f->len)
			pad[i++] = ' ';
	ft_memmove(pad + i, f->out, f->len);
	i = (int)f->len;
	if (f->flags & LEFT_ALIGN)
		while (i < size)
			pad[i++] = ' ';
	pad[size] = 0;
	free(f->out);
	f->out = pad;
	f->len = ft_strlen(pad);
	return (0);
}

int	apply_flags(t_format *fmt)
{
	if ((fmt->flags & PREFIX_SIGN || fmt->flags & PREFIX_BLANK) \
	&& process_prefix(fmt))
		return (-1);
	if ((fmt->flags & ZERO_PADDED) && zero_padding(fmt))
		return (-1);
	fmt->len = ft_strlen(fmt->out);
	if ((fmt->width || fmt->flags & LEFT_ALIGN) && space_padding(fmt))
		return (-1);
	return (0);
}
