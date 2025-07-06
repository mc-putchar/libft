#include "ft_printf.h"

int	ft_printf_basic_test(void)
{
	(void)ft_printf("");
	(void)ft_printf("\n");
	(void)ft_printf("ft_printf: Basic test: [EXCELLENT]\n");
	(void)ft_printf("Well done!\n");
	if (ft_printf("Congratulations!\n"))
		return (0);
	return (-1);
}
