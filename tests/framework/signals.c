/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:17:51 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/03 14:24:27 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libunit.h"

t_status	get_signal(int sig)
{
	if (sig == SIGSEGV)
		return (ERRSEGV);
	if (sig == SIGBUS)
		return (ERRBUS);
	if (sig == SIGABRT)
		return (ERRABRT);
	if (sig == SIGFPE)
		return (ERRFPE);
	if (sig == SIGPIPE)
		return (ERRPIPE);
	if (sig == SIGILL)
		return (ERRILL);
	if (sig == SIGALRM)
		return (TIMEOUT);
	return (OK);
}
