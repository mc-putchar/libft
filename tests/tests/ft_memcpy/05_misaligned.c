#include <stdlib.h>
#include <stdio.h>
#include "libft_mem.h"

int	misaligned_memcpy(void)
{
	char	src[] = "Hello, World!";
	char	dest[20];
	int		*intsrc;
	int		*intdest;
	int		i;

	ft_memcpy(dest + 1, src + 2, 10);
	dest[11] = '\0';
	if (ft_memcmp(dest + 1, "llo, World", 10) != 0)
		return (1);
	intsrc = malloc(sizeof(int) * 42 + 1);
	if (!intsrc)
		return (1);
	intdest = malloc(sizeof(int) * 42 + 1);
	if (!intdest)
		return (free(intsrc), 1);
	i = -1;
	while (++i < 42)
		intsrc[i] = i * 2137 + 42;
	ft_memcpy((char *)intdest + 1, (char *)intsrc + 2, sizeof(int) * 42 - 1);
	i = 0;
	if (ft_memcmp((char *)intdest + 1, (char *)intsrc + 2, sizeof(int) * 42 - 1))
	{
		for (i = 0; i < 42; ++i)
			if (intdest[i] != intsrc[i])
				printf("intdest[%d] = %d, intsrc[%d] = %d\n", i, intdest[i], i, intsrc[i]);
		i = 1;
	}
	free(intsrc);
	free(intdest);
	return (i);
}
