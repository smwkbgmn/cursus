#include "libft.h"

static int	ft_strlen(char const *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*result;
	unsigned int		idx;

	result = malloc(ft_strlen(s) + 1);
	if (result == 0)
		return (0);
	idx = 0;
	while (*s)
	{
		result[idx] = f(idx, *s);
		idx++;
		s++;
	}
	return (result);
}

static int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
