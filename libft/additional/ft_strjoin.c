#include "libft.h"

static int	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		idx;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == 0)
		return (0);
	idx = 0;
	while (*s1)
		result[idx++] = *s1++;
	while (*s2)
		result[idx++] = *s2++;
	result[idx] = 0;
	return (result);
}

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
