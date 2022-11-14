#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	idx;

	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	if (len == 0)
		*result = 0;
	else
	{
		idx = 0;
		while (s[start] && idx < len)
			result[idx++] = s[start++];
		result[idx] = 0;
	}
	return (result);
}
