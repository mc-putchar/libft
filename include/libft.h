/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:18:12 by mcutura           #+#    #+#             */
/*   Updated: 2024/12/23 08:25:36 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Memory operations */
# include "libft_mem.h"

/* String operations */
# include "libft_str.h"

/* Input/Output */
# include "libft_io.h"

/* Linked list */
# include "libft_lst.h"

/* GNL */
# include "get_next_line.h"

/* Print formatted */
# include "ft_printf.h"

/* Identity functions */
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isspace(int c);
int		ft_isnumber(char const *str);
int		is_separator(char c, const char *sep);

/* Conversion functions */
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
double	ft_atod(char const *str);

/* Unlabeled */
int		throw_error(int err, char const *msg);
void	print_error(char const *msg);

#endif
