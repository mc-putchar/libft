#include <stdlib.h>
#include <stdio.h>
#include "libft_mem.h"

int	unaligned_memmove(void)
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
	intdest[42] = 0xDEADBEEF;
	i = -1;
	while (++i < 42)
		intsrc[i] = -i;
	ft_memmove((char *)intdest + 1, (char *)intsrc + 1, sizeof(int) * 42 - 1);
	i = 0;
	if (ft_memcmp((char *)intdest + 1, (char *)intsrc + 1, sizeof(int) * 42 - 1))
	{
		for (i = 0; i < 42; ++i)
			if (intdest[i] != intsrc[i])
				printf("intdest[%d] = %d [%X], intsrc[%d] = %d [%X]\n", i, intdest[i], intdest[i], i, intsrc[i], intsrc[i]);
		i = 1;
	}
	free(intsrc);
	free(intdest);
	return (i);
}
