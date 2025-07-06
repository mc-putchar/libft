/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:55:36 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/12 01:20:21 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ansi_colors.h"
#include "libunit.h"

static char const	*g_status_name[] = {
	"INIT",
	"OK",
	"KO",
	"TIMEOUT",
	"SIGSEGV",
	"SIGBUS",
	"SIGABRT",
	"SIGFPE",
	"SIGPIPE",
	"SIGILL"
};

void	output_prerun(char const *func_name, t_test *test)
{
	if (COLOR_PRINT)
	{
		(void)printf("%s%s%s:%s %s: ", \
			WHTB, BBLK, func_name, CLR, test->name);
	}
	else
		(void)printf("%s: %s: \n", func_name, test->name);
}

int	exec_test(t_test *test, unsigned int timeout)
{
	pid_t	parent;
	int		status;
	int		pfd[2];

	if (pipe(pfd))
		return (throw_error(-1, "Error: pipe error."));
	parent = fork();
	if (parent < 0)
	{
		return (close(pfd[0]), close(pfd[1]), \
		throw_error(-1, "Error: fork it error."));
	}
	else if (!parent)
	{
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		(void)alarm(timeout);
		status = test->func();
		exit(status);
	}
	close(pfd[1]);
	return (pfd[0]);
}

void	output_result(t_test *test)
{
	if (COLOR_PRINT)
	{
		if (test->status == test->expect)
			(void)printf("%s", GRN);
		else
			(void)printf("%s", RED);
		(void)printf("[%s]%s\n", g_status_name[test->status], CLR);
	}
	else
		(void)printf("[%s]\n", g_status_name[test->status]);
}
