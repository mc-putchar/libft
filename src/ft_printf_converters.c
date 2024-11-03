/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:14:55 by mcutura           #+#    #+#             */
/*   Updated: 2024/06/22 04:02:49 by mcutura          ###   ########.fr       */
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

/* TODO: Add zero padding and blank prefix */
char	*int_con(t_format *fmt)
{
	char	*tmp;

	tmp = ft_itoa(fmt->u_arg.i);
	if (!tmp)
		return (NULL);
	if (!fmt->precision && !fmt->u_arg.i)
		tmp[0] = 0;
	fmt->len = ft_strlen(tmp);
	return (tmp);
}

char	*uint_con(t_format *fmt)
{
	char	*tmp;

	tmp = ft_itoa(fmt->u_arg.i);
	if (!tmp)
		return (NULL);
	if (!fmt->precision && tmp[0] == '0')
		tmp[0] = 0;
	fmt->len = ft_strlen(tmp);
	return (tmp);
}

char	*str_con(t_format *fmt)
{
	if (!fmt->u_arg.p)
	{
		fmt->len = 6;
		if (fmt->precision)
			return (ft_strdup("(null)"));
		fmt->len = 0;
		return (ft_strdup(""));
	}
	fmt->len = ft_strlen((const char *)fmt->u_arg.p);
	return (ft_strdup((const char *)fmt->u_arg.p));
}
