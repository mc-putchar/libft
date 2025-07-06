/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:51:26 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/12 00:24:56 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libunit.h"

t_unit	*create_test_unit(char const *func_name)
{
	return (create_timed_test_unit(func_name, 0));
}

t_unit	*create_timed_test_unit(char const *func_name, unsigned int sec)
{
	t_unit	*unit;

	unit = malloc(sizeof(*unit));
	if (!unit)
		return (NULL);
	unit->tests = NULL;
	unit->func_name = ft_strdup(func_name);
	if (!unit->func_name)
		return (free(unit), NULL);
	unit->total = 0;
	unit->passed = 0;
	unit->timeout = sec;
	unit->pipe = -1;
	unit->log = -1;
	return (unit);
}

int	add_test(t_unit *unit, char const *test_name, int (*test_f)(void))
{
	return (add_test_expect(unit, test_name, test_f, OK));
}

int	add_test_expect(t_unit *unit, char const *test_name, \
	int (*test_func)(void), t_status expected)
{
	t_test	*test;
	t_test	*last;

	test = malloc(sizeof(*test));
	if (!test)
		return (throw_error(1, "Error: malloc failed."));
	test->func = test_func;
	test->name = ft_strdup(test_name);
	if (!test->name)
		return (free(test), throw_error(1, "Error: malloc failed."));
	test->status = INIT;
	test->expect = expected;
	test->next = NULL;
	if (unit->tests)
	{
		last = unit->tests;
		while (last->next)
			last = last->next;
		last->next = test;
	}
	else
		unit->tests = test;
	return (0);
}

int	launch_unit(t_unit **test_unit)
{
	int	result;

	result = execute_test_unit(*test_unit);
	output_unit_results(*test_unit);
	free_unit(test_unit);
	return (result);
}
