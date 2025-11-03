#include "libunit.h"

extern int	basic_test_memcpy(void);
extern int	overlap_test_memcpy(void);
extern int	null_test_memcpy(void);
extern int	unaligned_memcpy(void);
extern int	misaligned_memcpy(void);

int	test_ft_memcpy_launcher(void)
{
	t_unit	*test_unit;
	int		error;

	test_unit = create_timed_test_unit("ft_memcpy", 10);
	(void)set_log(test_unit, "./ft_memcpy.log");
	if (!test_unit)
		return (-1);
	error = 0;
	error |= add_test(test_unit, "Basic test", basic_test_memcpy);
	error |= add_test_expect(test_unit, "Overlap test", \
		overlap_test_memcpy, KO);
	error |= add_test_expect(test_unit, "NULL test", \
		null_test_memcpy, ERRSEGV);
	error |= add_test(test_unit, "Unaligned test", unaligned_memcpy);
	error |= add_test(test_unit, "Misaligned test", misaligned_memcpy);
	if (error)
		return (free_unit(&test_unit), -1);
	return (launch_unit(&test_unit));
}
