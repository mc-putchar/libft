#include "libft_str.h"

int  ft_isint(char const *str)
{
    size_t const    len = ft_strlen(str);
    size_t          i;
    int             sign;

    i = 0;
    sign = 1;
    while (i < len && (str[i] == '-' || str[i] == '+'))
        if (str[i++] == '-')
            sign = -sign;
    if (i == len)
        return (0);
    while (i < len && str[i] == '0')
        ++i;
    if (i == len)
        return (1);
    if (len - i > 10)
        return (0);
    if (len - i == 10)
        if ((sign < 0 && ft_strncmp(&str[i], "2147483648", 10) > 0) \
        || (ft_strncmp(&str[i], "2147483647", 10) > 0))
            return (0);
    return (1);
}
