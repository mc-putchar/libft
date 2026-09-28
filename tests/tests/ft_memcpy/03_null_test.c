#include <stdlib.h>
#include "libft_mem.h"

int null_test_memcpy(void)
{
	void	*src;
	void	*dst;

	src = NULL;
	dst = malloc(sizeof(char) * 42);
	ft_memcpy(dst, src, 42);
	free(dst);
	return (-1);
}
