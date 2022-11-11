#include "libft.h"

static int	ft_strlen(char const *str);
int			is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		idx;

	result = malloc(ft_strlen(s1) + 1);
	if (result == 0)
		return (0);
	while (is_set(*s1, set) == 1 && *s1)
		s1++;
	idx = 0;
	while (*s1)
		result[idx++] = *s1++;
	result[idx] = 0;
	idx--;
	while (is_set(result[idx], set) == 1 && idx > 0)
		result[idx--] = 0;
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

int	is_set(char c, char const *set)
{
	while (*set != c && *set)
		set++;
	if (*set != 0)
		return (1);
	else
		return (0);
}
