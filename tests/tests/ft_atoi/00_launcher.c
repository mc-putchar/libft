#include "libunit.h"

extern int	ft_atoi_small_nums_test(void);
extern int	ft_atoi_negative_nums_test(void);
extern int	ft_atoi_full_range_test(void);

int	test_ft_atoi_launcher(void)
{
	t_unit	*test_unit;
	int		error;

	test_unit = create_timed_test_unit("ft_atoi", 10);
	if (!test_unit)
		return (-1);
	error = 0;
	error |= add_test(test_unit, "Small numbers test", \
		&ft_atoi_small_nums_test);
	error |= add_test(test_unit, "Negative numbers test", \
		&ft_atoi_negative_nums_test);
	error |= add_test(test_unit, "Full range test", \
		&ft_atoi_full_range_test);
	if (error)
		return (-1);
	return (launch_unit(&test_unit));
}
