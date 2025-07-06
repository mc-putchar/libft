/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi_colors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:52:04 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/03 13:52:52 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_COLORS_H
# define ANSI_COLORS_H

// Text color
# define BLK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GRN	"\033[0;32m"
# define YEL	"\033[0;33m"
# define BLU	"\033[0;34m"
# define MAG	"\033[0;35m"
# define CYN	"\033[0;36m"
# define WHT	"\033[0;37m"

// Bold
# define BBLK	"\033[1;30m"
# define BRED	"\033[1;31m"
# define BGRN	"\033[1;32m"
# define BYEL	"\033[1;33m"
# define BBLU	"\033[1;34m"
# define BMAG	"\033[1;35m"
# define BCYN	"\033[1;36m"
# define BWHT	"\033[1;37m"

// Underline
# define UBLK	"\033[4;30m"
# define URED	"\033[4;31m"
# define UGRN	"\033[4;32m"
# define UYEL	"\033[4;33m"
# define UBLU	"\033[4;34m"
# define UMAG	"\033[4;35m"
# define UCYN	"\033[4;36m"
# define UWHT	"\033[4;37m"

// Background
# define BLKB	"\033[40m"
# define REDB	"\033[41m"
# define GRNB	"\033[42m"
# define YELB	"\033[43m"
# define BLUB	"\033[44m"
# define MAGB	"\033[45m"
# define CYNB	"\033[46m"
# define WHTB	"\033[47m"

// Clear color
# define CLR	"\033[0m"

#endif // ANSI_COLORS_H
