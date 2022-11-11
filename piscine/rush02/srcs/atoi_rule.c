#include "rush.h"

char *pass_space(char *str);
char *pass_sign(char *str);
char *pass_zero(char *str);
int is_digit(char letter);

char *apply_atoi_rule(char *dest, char *src)
{
	char *applied;

	src = pass_space(src);
	src = pass_sign(src);
	src = pass_zero(src);

	if (is_digit(*src) == 0)
		return (ft_strcpy(dest, "0"));
	
	applied = (char *)malloc(sizeof(char) * (get_length(src) + 1));
	*applied = 0;

	while (is_digit(*src) == 1)
		ft_strncat(applied, src++, 1);

	ft_strcpy(dest, applied);
	free(applied);
	
	return (dest);
}

char *pass_space(char *str)
{
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	return (str);
}

char *pass_sign(char *str)
{
	while (*str == '+' || *str == '-')
		str++;
	return (str);
}

char *pass_zero(char *str)
{
	while (*str == '0')
		str++;
	return (str);
}

int is_digit(char letter)
{
	if ('0' <= letter && letter <= '9')
		return (1);
	return (0);
}