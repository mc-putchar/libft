/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:48:01 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/12 00:17:54 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
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

int	set_log(t_unit *unit, char const *filepath)
{
	unit->log = open_log(filepath);
	return (unit->log);
}

static int	wait_for_test(t_test *test)
{
	pid_t		child;
	int			status;

	child = wait(&status);
	if (child < 0)
		return (throw_error(1, "Error: wait error.\n"));
	test->status = get_signal(WTERMSIG(status));
	if (test->status == OK && status)
		test->status = KO;
	return ((test->status != test->expect) * -1);
}

int	execute_test_unit(t_unit *unit)
{
	t_test	*test;
	int		result;

	test = unit->tests;
	while (test && ++unit->total)
		test = test->next;
	result = 0;
	test = unit->tests;
	while (test)
	{
		unit->pipe = exec_test(test, unit->timeout);
		if (unit->pipe < 0)
			(void)printf("Something went wrong\n");
		else
		{
			output_prerun(unit->func_name, test);
			handle_log(unit->log, unit->pipe);
			result = wait_for_test(test);
			if (!result)
				++unit->passed;
			output_result(test);
		}
		test = test->next;
	}
	return (-1 * (unit->passed != unit->total));
}

void	output_unit_results(t_unit *unit)
{
	t_status	status;

	if (unit->passed == unit->total)
		status = OK;
	else
		status = KO;
	if (COLOR_PRINT)
	{
		if (status == OK)
			(void)printf("\n%s%s%s:%s%s ", \
				GRNB, BBLK, unit->func_name, CLR, GRN);
		else
			(void)printf("\n%s%s%s:%s%s ", \
				REDB, BBLK, unit->func_name, CLR, RED);
		(void)printf("[%s] %d / %d tests passed%s\n\n", \
			g_status_name[status], unit->passed, unit->total, CLR);
	}
	else
	{
		(void)printf("\n%s: [%s] %d / %d tests passed\n\n", \
			unit->func_name, g_status_name[status], unit->passed, unit->total);
	}
}

void	free_unit(t_unit **unit)
{
	t_test	*node;
	t_test	*next;

	close((*unit)->log);
	free((void *)((*unit)->func_name));
	node = (*unit)->tests;
	while (node)
	{
		next = node->next;
		free((void *)(node->name));
		free(node);
		node = next;
	}
	free(*unit);
	*unit = NULL;
}
