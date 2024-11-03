/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:40:10 by mcutura           #+#    #+#             */
/*   Updated: 2024/08/03 16:24:50 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

static char	*to_hex_str(unsigned long long n, int offset, int prefix);

char	*hex_con(t_format *fmt)
{
	char	*tmp;

	tmp = to_hex_str(fmt->u_arg.ui, HEX_OFFSET_LOWER, fmt->flags & ALT_FORM);
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

	tmp = to_hex_str(fmt->u_arg.ui, HEX_OFFSET_UPPER, fmt->flags & ALT_FORM);
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
	tmp = ft_strjoin("0x", \
		to_hex_str((unsigned long long)fmt->u_arg.p, HEX_OFFSET_LOWER, 1));
	if (tmp)
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

char	*to_hex_str(unsigned long long n, int offset, int prefix)
{
	char	*hex;
	int		i;

	i = count_digits(n);
	hex = malloc(i + 1 + ((prefix != 0) * 2));
	if (!hex)
		return (NULL);
	if (!n || prefix)
		hex[0] = '0';
	hex[i] = 0;
	if (n && prefix)
		hex[1] = 'Q' + offset;
	while (n && i--)
	{
		hex[i] = (n & 0xF) + '0';
		if (hex[i] > '9')
			hex[i] += offset;
		n >>= 4;
	}
	return (hex);
}
