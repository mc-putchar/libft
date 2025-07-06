/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:14:55 by mcutura           #+#    #+#             */
/*   Updated: 2025/07/06 02:32:51 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

char	*char_con(t_format *fmt)
{
	char	*tmp;

	if (fmt->width > 1)
		tmp = malloc(fmt->width);
	else
		tmp = malloc(1);
	if (!tmp)
	{
		fmt->len = 0;
		return (NULL);
	}
	fmt->len = 1;
	tmp[0] = (char)fmt->u_arg.i;
	if (fmt->width > 1)
	{
		if (fmt->flags & LEFT_ALIGN)
			ft_memset(tmp + 1, 32, fmt->width - 1);
		else
		{
			tmp[fmt->width - 1] = tmp[0];
			ft_memset(tmp, 32, fmt->width - 1);
		}
		fmt->len = fmt->width;
	}
	return (tmp);
}

char	*int_con(t_format *fmt)
{
	char		*tmp;
	int			i;
	int const	neg = (fmt->u_arg.i < 0);
	int const	sign = neg || ((fmt->flags & PREFIX_SIGN) != 0);

	tmp = ft_itoa(fmt->u_arg.i);
	if (!tmp)
		return (NULL);
	if (!fmt->precision && !fmt->u_arg.i)
		tmp[0] = 0;
	fmt->len = ft_strlen(tmp);
	if (fmt->precision <= (int)fmt->len - neg)
		return (tmp);
	if (safe_alloc(&(fmt->out), fmt->precision + sign + 1))
		return (free(tmp), NULL);
	i = sign;
	if (sign)
		fmt->out[0] = '+' + (neg * 2);
	while (i - sign < fmt->precision - (int)fmt->len + neg)
		fmt->out[i++] = '0';
	ft_memmove(fmt->out + i, tmp + neg, fmt->len - neg);
	fmt->out[fmt->precision + sign] = 0;
	fmt->len = fmt->precision + sign;
	return (free(tmp), fmt->out);
}

char	*uint_con(t_format *fmt)
{
	char	*tmp;
	int		i;

	tmp = ft_uitoa(fmt->u_arg.i);
	if (!tmp)
		return (NULL);
	if (!fmt->precision && tmp[0] == '0')
		tmp[0] = 0;
	fmt->len = ft_strlen(tmp);
	if (fmt->precision > (int)fmt->len)
	{
		i = 0;
		if (safe_alloc(&(fmt->out), fmt->precision + 1))
			return (free(tmp), NULL);
		while (i < fmt->precision - (int)fmt->len)
			fmt->out[i++] = '0';
		ft_memmove(fmt->out + i, tmp, fmt->len);
		fmt->out[fmt->precision] = 0;
		fmt->len = fmt->precision;
		free(tmp);
		return (fmt->out);
	}
	return (tmp);
}

char	*str_con(t_format *fmt)
{
	char	*str;

	if (!fmt->u_arg.p)
	{
		fmt->len = 6;
		if (fmt->precision)
			return (ft_strdup("(null)"));
		fmt->len = 0;
		return (ft_strdup(""));
	}
	fmt->len = ft_strlen((const char *)fmt->u_arg.p);
	if (fmt->precision < 0 || fmt->precision >= (int)fmt->len)
		return (ft_strdup((const char *)fmt->u_arg.p));
	if (safe_alloc(&str, fmt->precision + 1))
		return (NULL);
	fmt->len = fmt->precision;
	if (fmt->precision)
		ft_memmove(str, (const char *)fmt->u_arg.p, fmt->precision);
	str[fmt->precision] = 0;
	return (str);
}
