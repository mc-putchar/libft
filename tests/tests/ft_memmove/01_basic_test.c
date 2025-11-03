#include "libft_mem.h"
#include "libft_str.h"

int basic_test_memmove(void)
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
	char				buff[256];

	idx = 0;
	while (idx < 6)
	{
		ft_memmove(buff, inputs[idx], ft_strlen(inputs[idx]) + 1);
		if (ft_memcmp(buff, inputs[idx], ft_strlen(inputs[idx]) + 1) != 0)
			return (-1);
		++idx;
	}
	return (0);
}
