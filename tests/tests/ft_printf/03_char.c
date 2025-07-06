#include "ft_printf.h"

int	ft_printf_char_test(void)
{
	char	c;

	c = ' ';
	while (c <= 'z')
		if (ft_printf("%c", c++) != 1)
			return (-1);
	return (0);
}
