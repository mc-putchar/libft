#include "libunit.h"

extern int	basic_test_memmove(void);
extern int	overlap_test_memmove(void);
extern int	null_test_memmove(void);
extern int	unaligned_memmove(void);
extern int	misaligned_memmove(void);

int	test_ft_memmove_launcher(void)
{
	t_unit	*test_unit;
	int		error;

	test_unit = create_timed_test_unit("ft_memmove", 10);
	(void)set_log(test_unit, "./ft_memmove.log");
	if (!test_unit)
		return (-1);
	error = 0;
	error |= add_test(test_unit, "Basic test", basic_test_memmove);
	error |= add_test(test_unit, "Overlap test", overlap_test_memmove);
	error |= add_test_expect(test_unit, \
		"NULL test", null_test_memmove, ERRSEGV);
	error |= add_test(test_unit, "Unaligned test", unaligned_memmove);
	error |= add_test(test_unit, "Misaligned test", misaligned_memmove);
	if (error)
		return (free_unit(&test_unit), -1);
	return (launch_unit(&test_unit));
}
