#include <string.h>
#include "libft.h"

int basic_test(void)
{
	static char const	*inputs[] = {
		"test",
		"string",
		"Lorem ipsum",
		"The quick brown fox jumps over the lazy dog",
		"ALL UR BASE R BELONG 2 US",
		"Ph`nglui mglw`nafh Cthulhu R`lyeh wgah`nagl fhtagn..."
	};
	int					idx;

	idx = 0;
	while (idx < 6)
	{
		if (ft_strlen(inputs[idx]) != strlen(inputs[idx]))
			return (-1);
		++idx;
	}
	return (0);
}
