#include <stdlib.h>
#include <stdio.h>
#include "libft_mem.h"

int	unaligned_memcpy(void)
{
	int		*intsrc;
	int		*intdest;
	int		i;

	intsrc = malloc(sizeof(int) * 43);
	if (!intsrc)
		return (1);
	intdest = malloc(sizeof(int) * 43);
	if (!intdest)
		return (free(intsrc), 1);
	intdest[0] = 0xDEADBEEF;
	intdest[41] = 0xCAFEBABE;
	intdest[42] = 0xDEADBEEF;
	i = -1;
	while (++i < 42)
		intsrc[i] = -i;
	ft_memcpy((char *)intdest + 1, (char *)intsrc + 1, sizeof(int) * 42 - 1);
	i = 0;
	if (ft_memcmp((char *)intdest + 1, (char *)intsrc + 1, sizeof(int) * 42 - 1))
	{
		for (i = 0; i < 6; ++i)
			printf("[%d] DST: %0X, SRC: %0X\n", i, intdest[i], intsrc[i]);
			// if (intdest[i] != intsrc[i])
		i = 1;
	}
	free(intsrc);
	free(intdest);
	return (i);
}
