#include "libunit.h"

extern int	ft_printf_basic_test(void);
extern int	ft_printf_null_fmt_test(void);
extern int	ft_printf_char_test(void);
extern int	ft_printf_str_test(void);
// extern int	ft_printf_ptr_test(void);
// extern int	ft_printf_format_test(void);

int	test_ft_printf_launcher(void)
{
	t_unit	*test_unit;
	int		error;

	test_unit = create_timed_test_unit("ft_printf", 10);
	(void)set_log(test_unit, "./ft_printf.log");
	if (!test_unit)
		return (-1);
	error = 0;
	error |= add_test(test_unit, "Basic test", ft_printf_basic_test);
	error |= add_test_expect(test_unit, \
		"NULL format test", ft_printf_null_fmt_test, ERRSEGV);
	error |= add_test(test_unit, "Char test", ft_printf_char_test);
	error |= add_test(test_unit, "String test", ft_printf_str_test);
	if (error)
		return (free_unit(&test_unit), -1);
	return (launch_unit(&test_unit));
}
