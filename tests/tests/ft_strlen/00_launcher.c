#include "libunit.h"

extern int	basic_test(void);
extern int	null_test(void);
extern int	bigger_str_test(void);

int	test_ft_strlen_launcher(void)
{
	t_unit	*test_unit;
	int		error;

	test_unit = create_test_unit("ft_strlen");
	if (!test_unit)
		return (-1);
	error = 0;
	error |= add_test(test_unit, "Basic test", &basic_test);
	error |= add_test_expect(test_unit, "NULL test", &null_test, ERRSEGV);
	error |= add_test(test_unit, "Bigger string test", &bigger_str_test);
	if (error)
		return (-1);
	return (launch_unit(&test_unit));
}
