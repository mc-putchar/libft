/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:35:15 by mcutura           #+#    #+#             */
/*   Updated: 2025/07/06 02:34:38 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

# define PRINTF_SPECIFIERS	"%cdiuxXsp"
# define SPEC_PERC			0
# define SPEC_CHAR			1
# define SPEC_DEC			2
# define SPEC_INT			3
# define SPEC_UINT			4
# define SPEC_HEX_LOWER		5
# define SPEC_HEX_UPPER		6
# define SPEC_STRING		7
# define SPEC_POINTER		8
# define PRINTF_FLAGS		"-0# +"
# define LEFT_ALIGN			1
# define ZERO_PADDED		2
# define ALT_FORM			4
# define PREFIX_BLANK		8
# define PREFIX_SIGN		16

# define HEX_OFFSET_LOWER	39
# define HEX_OFFSET_UPPER	7

typedef struct s_format
{
	int		width;
	int		precision;
	int		specifier;
	int		flags;
	char	*out;
	size_t	len;
	union
	{
		int				i;
		unsigned int	ui;
		void			*p;
	}		u_arg;
}	t_format;

typedef char	*(*t_converter)(struct s_format *);

char	*char_con(t_format *fmt);
char	*int_con(t_format *fmt);
char	*uint_con(t_format *fmt);
char	*hex_con(t_format *fmt);
char	*uhex_con(t_format *fmt);
char	*str_con(t_format *fmt);
char	*ptr_con(t_format *fmt);

int		indexof(char c, char *str);
int		safe_alloc(char **ptr, size_t size);
void	parse_format(t_format *fmt, const char *format, int *i);
int		apply_flags(t_format *fmt);

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vprintf(int fd, const char *format, va_list ap);

#endif // FT_PRINTF_H
