/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:58:32 by mcutura           #+#    #+#             */
/*   Updated: 2025/07/05 20:47:43 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int	indexof(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	if (str[i])
		return (i);
	return (-1);
}

static int	get_precision(const char *format, int *i)
{
	int	precision;
	int	reset;

	precision = 0;
	reset = 0;
	if (format[(*i) + 1] == '-')
	{
		reset = -1;
		++(*i);
	}
	while (ft_isdigit(format[++(*i)]))
		precision = precision * 10 + format[*i] - '0';
	if (reset)
		return (reset);
	return (precision);
}

static int	parse_flags(const char *format, int *i)
{
	int	flags;
	int	n;

	flags = 0;
	while (format[*i])
	{
		n = indexof(format[*i], PRINTF_FLAGS);
		if (n < 0)
			break ;
		flags |= 1 << n;
		++(*i);
	}
	return (flags);
}

/*
 * Format: %[flags][width][.precision]type
 */
void	parse_format(t_format *fmt, const char *format, int *i)
{
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->specifier = -1;
	if (format[++(*i)])
	{
		fmt->flags = parse_flags(format, i);
		while (ft_isdigit(format[*i]))
			fmt->width = fmt->width * 10 + format[(*i)++] - '0';
		if (format[*i] == '.')
			fmt->precision = get_precision(format, i);
		fmt->specifier = indexof(format[*i], PRINTF_SPECIFIERS);
	}
}

int	safe_alloc(char **ptr, size_t size)
{
	if (!ptr || !size)
		return (-1);
	*ptr = malloc(size);
	if (!*ptr)
		return (-1);
	return (0);
}
