#include "libft.h"

int	ft_atoi_negative_nums_test(void)
{
	static char const	*inputs[] = {
		"-0", "-1", "-2", "-3", "-4", "-5", "-6", "-7", "-8", "-9", "-10",
		"-11", "-12", "-13", "-14", "-15", "-16", "-17", "-18", "-19", "-20"
	};
	int					idx;

	idx = 0;
	while (idx < 21)
	{
		if (ft_atoi(inputs[idx]) != -idx)
			return (-1);
		++idx;
	}
	return (0);
}
