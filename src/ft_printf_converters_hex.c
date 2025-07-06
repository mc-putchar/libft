/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:40:10 by mcutura           #+#    #+#             */
/*   Updated: 2025/07/06 02:32:45 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

static char	*to_hex_str(unsigned long long n, int offset, int prefix, int prec);

char	*hex_con(t_format *fmt)
{
	char	*tmp;

	tmp = to_hex_str(fmt->u_arg.ui, HEX_OFFSET_LOWER, \
		((fmt->flags & ALT_FORM) > 0) * 1, fmt->precision);
	if (!tmp)
		return (NULL);
	if (!fmt->precision && !fmt->u_arg.ui)
		tmp[0] = 0;
	fmt->len = ft_strlen(tmp);
	return (tmp);
}

char	*uhex_con(t_format *fmt)
{
	char	*tmp;

	tmp = to_hex_str(fmt->u_arg.ui, HEX_OFFSET_UPPER, \
		((fmt->flags & ALT_FORM) > 0) * 2, fmt->precision);
	if (!tmp)
		return (NULL);
	if (!fmt->precision && !fmt->u_arg.ui)
		tmp[0] = 0;
	fmt->len = ft_strlen(tmp);
	return (tmp);
}

char	*ptr_con(t_format *fmt)
{
	char	*tmp;

	if (!fmt->u_arg.p)
	{
		fmt->len = 5;
		return (ft_strdup("(nil)"));
	}
	tmp = to_hex_str((unsigned long long)fmt->u_arg.p, HEX_OFFSET_LOWER, 1, \
		fmt->precision);
	if (!tmp)
		return (NULL);
	fmt->len = ft_strlen(tmp);
	return (tmp);
}

static int	count_digits(unsigned long long n)
{
	int	d;

	d = 0;
	if (!n)
		return (1);
	while (n)
	{
		n >>= 4;
		++d;
	}
	return (d);
}

char	*to_hex_str(unsigned long long n, int offset, int prefix, int prec)
{
	char	*hex;
	int		digits;
	size_t	len;

	digits = count_digits(n);
	len = digits + ((n != 0) * (prefix != 0) * 2);
	if (prec > digits)
		len += (prec - digits);
	if (safe_alloc(&hex, len + 1))
		return (NULL);
	if (!n || prefix)
		hex[0] = '0';
	hex[len] = 0;
	if (n && prefix)
		hex[1] = 'Q' + offset;
	while ((int)len-- > ((prefix != 0) * 2))
	{
		hex[len] = (n & 0xF) + '0';
		if (hex[len] > '9')
			hex[len] += offset;
		n >>= 4;
	}
	return (hex);
}
