#include <limits.h>
#include <stdlib.h>
#include "libft.h"

#define BUFFAH_SIZE	16

int	ft_atoi_full_range_test(void)
{
	int		idx;
	char	*numbah;
	char	buffah[BUFFAH_SIZE];

	idx = INT_MIN;
	while (idx < INT_MAX)
	{
		numbah = ft_itoa(idx); // What could go wrong
		(void)ft_strlcpy(buffah, numbah, BUFFAH_SIZE - 1);
		free(numbah);
		if (ft_atoi(buffah) != idx)
			return (-1);
		if (idx > INT_MAX - 123)
			break;
		idx += 123;
	}
	numbah = ft_itoa(INT_MAX);
	(void)ft_strlcpy(buffah, numbah, BUFFAH_SIZE - 1);
	free(numbah);
	return (-1 * (ft_atoi(buffah) != INT_MAX));
}
