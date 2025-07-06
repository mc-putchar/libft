#include <string.h>
#include "libft.h"

int null_test(void)
{
	if (ft_strlen(NULL) == 0)
		return (0);
	return (-1);
}
