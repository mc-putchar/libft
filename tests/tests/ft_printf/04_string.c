#include "ft_printf.h"

int	ft_printf_str_test(void)
{
	if (ft_printf("%s: %s: %d\n", __FILE__, __FUNCTION__, __LINE__))
		return (0);
	return (-1);
}
