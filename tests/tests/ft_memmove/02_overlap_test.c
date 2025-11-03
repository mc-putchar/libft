#include <stdlib.h>
#include "libft_mem.h"

int overlap_test_memmove(void)
{
	int	*arr1;
	int	*arr2;
	int	i;

	arr1 = malloc(100 * sizeof(int));
	if (!arr1)
		return (-1);
	i = -1;
	while (++i < 100)
		arr1[i] = i;
	arr2 = arr1 + 20;
	ft_memmove(arr2, arr1, 42 * sizeof(int));
	i = -1;
	while (++i < 42)
		if (arr2[i] != i)
			return (free(arr1), -1);
	free(arr1);
	return (0);
}
